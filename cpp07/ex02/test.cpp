#include <iostream>

int main() {
	int a = 42;
	int *b = new int(43);
	std::cout << "Hello, World!" << std::endl;
	std::cout << "a = " << a << ", *b = " << *b << std::endl;
	delete b;
	return 0;
}
