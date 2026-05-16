#include <iostream>

#include "AlienNumber.hpp"

using std::cout;


int main(void) {
	cout << "Hello, World!" << std::endl;
	AlienNumber a(5);
	AlienNumber b(10);
	AlienNumber c = a + b;
	AlienNumber d = a - b;

	cout << "AlienNumber c value: " << c.getValue() << std::endl;
	cout << "AlienNumber d value: " << d.getValue() << std::endl;

	return 0;
}
