#include "Dog.hpp"

// Constructor (default)
Dog::Dog() {
	std::cout << ">>> Dog default constructor\n";
}

// Constructor (parameterized)
Dog::Dog(std::string type) : Animal(type) {
	std::cout << ">>> Dog parameterized constructor\n";
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << ">>> Dog copy constructor\n";
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		_type = other._type;
	return *this;
	std::cout << ">>> Dog copy assignment operator\n";
}

// Destructor
Dog::~Dog() {
	std::cout << ">>> Dog class destructor\n";
}

// Public methods
void Dog::makeSound( void ) {
	std::cout << B_GREEN << "🐶 Making a dog sound. Woof woof!\n" << RESET;
}
