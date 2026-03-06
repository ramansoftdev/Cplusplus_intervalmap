#pragma once

#include<map>
#include<type_traits>
#include<iostream>
template<typename K, typename V>
class interval_map {


    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;


public:
    template<typename V_forward>
    interval_map(V_forward&& val) :m_valBegin(std::forward<V_forward>(val))
    {
        //std::cout << "creating interval map with default " << m_valBegin << std::endl;
    }



    V const& operator[](K const& key) const
    {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
            return m_valBegin;
        }
        else {
            return (--it)->second;
        }
    }

    template<typename V_forward>
    void assign(K const& keyBegin, K const& keyEnd, V_forward&& val)
        requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
    {
        if (!(keyBegin < keyEnd)) return;

        auto itKeyEndNext = m_map.upper_bound(keyEnd);
        auto itKeyEndPrev = (itKeyEndNext == m_map.begin()) ? m_map.end() : std::prev(itKeyEndNext);

        V const& valEnd = (itKeyEndPrev == m_map.end()) ? m_valBegin : itKeyEndPrev->second;

        if (!(valEnd == val)) {
            itKeyEndNext = m_map.insert_or_assign(itKeyEndNext, keyEnd, valEnd);
        }


        //auto itKeyBeginNext = m_map.lower_bound(keyBegin);

        auto itKeyBeginNext = itKeyEndNext;
        while (itKeyBeginNext != m_map.begin()) {
            auto prev = std::prev(itKeyBeginNext);
            if (prev->second < keyBegin) {
                break; // Stop! The element to the left is outside our range.
            }
            itKeyBeginNext = prev; // Step back.
        }



        auto itKeyBeginPrev = (itKeyBeginNext == m_map.begin()) ? m_map.end() : std::prev(itKeyBeginNext);

        V const& valBefore = (itKeyBeginPrev == m_map.end()) ? m_valBegin : itKeyBeginPrev->second;

        if (!(valBefore == val)) {
            itKeyBeginNext = m_map.insert_or_assign(itKeyBeginNext, keyBegin, std::forward<V_forward>(val));
        }
        else {
            itKeyBeginNext = itKeyBeginPrev;
        }

        auto delStart = (itKeyBeginNext == m_map.end()) ? m_map.begin() : std::next(itKeyBeginNext);

        if ((delStart != m_map.end()) && (delStart != itKeyEndNext)) {
            m_map.erase(delStart, itKeyEndNext);
        }

        /*if (!m_map.empty() && (m_map.begin()->second == m_valBegin)) {
            m_map.erase(m_map.begin());
        }*/



    }

    /*template<typename V_forward>
    void assign2(K const& keyBegin, K const& keyEnd, V_forward&& val)
        requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
    {
        if (!(keyBegin < keyEnd)) return;

        auto itKeyEndNext = m_map.upper_bound(keyEnd);
        auto itKeyEndPrev = (itKeyEndNext == m_map.begin()) ? m_map.end(): std::prev(itKeyEndNext);

        V const& valEnd = (itKeyEndPrev == m_map.end()) ? m_valBegin : itKeyEndPrev->second;

        if (!(valEnd == val)) {
            itKeyEndNext = m_map.insert_or_assign(itKeyEndNext, keyEnd, valEnd);
        }


        auto itKeyBeginNext = m_map.lower_bound(keyBegin);
        auto itKeyBeginPrev = (itKeyBeginNext == m_map.begin()) ? m_map.end() : std::prev(itKeyBeginNext);

        V const& valBefore = (itKeyBeginPrev == m_map.end()) ? m_valBegin : itKeyBeginPrev->second;

        if (!(valBefore == val)) {
            itKeyBeginNext = m_map.insert_or_assign(itKeyBeginNext, keyBegin, std::forward<V_forward>(val));
        }
        else {
            itKeyBeginNext = itKeyBeginPrev;
        }

        auto delStart = (itKeyBeginNext == m_map.end()) ? m_map.begin() : std::next(itKeyBeginNext);

        if ((delStart != m_map.end()) && (delStart != itKeyEndNext)) {
            m_map.erase(delStart, itKeyEndNext);
        }

        if (!m_map.empty() && (m_map.begin()->second == m_valBegin)) {
            m_map.erase(m_map.begin());
        }



    }

    */

};

