#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
	std::cout << "default constructor" << std::endl;
}

Animal::Animal(int age, std::string name) {}

Animal::~Animal() {}