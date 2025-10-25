#include "Dog.hpp"

// Constructor (default)
Dog::Dog() {
	std::cout << ">> 🐶 Dog default constructor\n";
	type_ = "Dog";
}

//// Constructor (parameterized)
//Dog::Dog(std::string type) : Animal(type) {
//	std::cout << ">> Dog parameterized constructor\n";
//}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << ">> 🐶 Dog copy constructor\n";
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		type_ = other.type_;
	return *this;
	std::cout << ">> 🐶 Dog copy assignment operator\n";
}

// Destructor
Dog::~Dog() {
	std::cout << ">> 🐶 Dog class destructor\n";
}

// Public methods
void Dog::makeSound( void ) const {
	std::cout << B_GREEN << "🐶 Making a dog sound. Woof woof!" << RESET << std::endl;
}
