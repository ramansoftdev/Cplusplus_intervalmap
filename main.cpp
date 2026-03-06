#include<iostream>
#include"interval_map.h"
#include<string>
#include<cassert>

class popcorn {
	std::string value;
public:
	// Default constructor
	popcorn() : value("") {}
	
	// Constructor with string
	popcorn(const std::string& v) : value(v) {
		std::cout << "popcorn constructed: " << value << std::endl;
	}
	
	// Copy constructor
	popcorn(const popcorn& other) : value(other.value) {
		std::cout << "popcorn copy constructed: " << value << std::endl;
	}
	
	// Move constructor
	popcorn(popcorn&& other) noexcept : value(std::move(other.value)) {
		std::cout << "popcorn move constructed: " << value << std::endl;
	}
	
	// Copy assignment
	popcorn& operator=(const popcorn& other) {
		if (this != &other) {
			value = other.value;
			std::cout << "popcorn copy assigned: " << value << std::endl;
		}
		return *this;
	}
	
	// Move assignment
	popcorn& operator=(popcorn&& other) noexcept {
		if (this != &other) {
			value = std::move(other.value);
			std::cout << "popcorn move assigned: " << value << std::endl;
		}
		return *this;
	}
	
	// Less than operator
	bool operator<(const popcorn& other) const {
		return value < other.value;
	}
	
	const std::string& get_value() const { return value; }
};

class size {
	std::string value;
public:
	// Default constructor
	size() : value("") {}
	
	// Constructor with string
	size(const std::string& v) : value(v) {
		std::cout << "size constructed: " << value << std::endl;
	}
	
	// Copy constructor
	size(const size& other) : value(other.value) {
		std::cout << "size copy constructed: " << value << std::endl;
	}
	
	// Move constructor
	size(size&& other) noexcept : value(std::move(other.value)) {
		std::cout << "size move constructed: " << value << std::endl;
	}
	
	// Copy assignment
	size& operator=(const size& other) {
		if (this != &other) {
			value = other.value;
			std::cout << "size copy assigned: " << value << std::endl;
		}
		return *this;
	}
	
	// Move assignment
	size& operator=(size&& other) noexcept {
		if (this != &other) {
			value = std::move(other.value);
			std::cout << "size move assigned: " << value << std::endl;
		}
		return *this;
	}
	
	// Equality operator
	bool operator==(const size& other) const {
		return value == other.value;
	}
	
	const std::string& get_value() const { return value; }
};

void IntervalMapTest() {
	std::cout << "\n=== Testing interval_map<char, int> ===" << std::endl;



	{
		interval_map< int, char> map('X');

		map.assign(5, 10, 'A');
		map.assign(15, 25, 'X');

		assert(map[4] == 'X');
		assert(map[5] == 'A');
		assert(map[9] == 'A');
		assert(map[10] == 'X');
		assert(map[12] == 'X');
		assert(map[15] == 'X');
		assert(map[20] == 'X');
		assert(map[25] == 'X');
		assert(map[30] == 'X');

		std::cout << "\n=== Test Complete ===" << std::endl;
	}

	//{
	//	interval_map<int, std::string> map(std::string("mango"));

	//	map.assign(5, 10, std::string("apple"));
	//	map.assign(15, 25, std::string("mango"));

	//	assert(map[4] == std::string("mango"));
	//	assert(map[5] == std::string("apple"));
	//	assert(map[9] == std::string("apple"));
	//	assert(map[10] == std::string("mango"));
	//	assert(map[12] == std::string("mango"));
	//	assert(map[15] == std::string("mango"));
	//	assert(map[20] == std::string("mango"));
	//	assert(map[25] == std::string("mango"));
	//	assert(map[30] == std::string("mango"));

	//	std::cout << "\n=== Test Complete ===" << std::endl;
	//}

	//{
	//	interval_map<std::string, int> map(100);

	//	map.assign(std::string("cat"), std::string("dog"), 50);
	//	map.assign(std::string("fish"), std::string("lion"), 100);

	//	assert(map[std::string("apple")] == 100);
	//	assert(map[std::string("cat")] == 50);
	//	assert(map[std::string("cow")] == 50);
	//	assert(map[std::string("dog")] == 100);
	//	assert(map[std::string("elephant")] == 100);
	//	assert(map[std::string("fish")] == 100);
	//	assert(map[std::string("giraffe")] == 100);
	//	assert(map[std::string("lion")] == 100);
	//	assert(map[std::string("zebra")] == 100);

	//	std::cout << "\n=== Test Complete ===" << std::endl;
	//}

	//{
	//	interval_map<popcorn, size> map(size("XL"));

	//	map.assign(popcorn("butter"), popcorn("caramel"), size("S"));
	//	map.assign(popcorn("cheese"), popcorn("kettle"), size("XL"));

	//	assert(map[popcorn("apple")] == size("XL"));
	//	assert(map[popcorn("butter")] == size("S"));
	//	assert(map[popcorn("caramel")] == size("XL"));
	//	assert(map[popcorn("cheese")] == size("XL"));
	//	assert(map[popcorn("honey")] == size("XL"));
	//	assert(map[popcorn("kettle")] == size("XL"));
	//	assert(map[popcorn("plain")] == size("XL"));

	//	std::cout << "\n=== Test Complete ===" << std::endl;
	//}
}

int main() {

	std::cout << "=====================beginning interval_map======================" << std::endl;

	// Run the interval map test
	IntervalMapTest();
	
	return 0;
}