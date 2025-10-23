#include "Animal.hpp"

// Constructor (default)
Animal::Animal() {
	std::cout << ">>> Animal default constructor\n";
}

// Constructor (parameterized)
Animal::Animal(std::string type) : _type(type) {
	std::cout << ">>> Animal parameterized constructor\n";
}

// Copy constructor
Animal::Animal(const Animal &other) : _type(other._type)	{
	std::cout << ">>> Animal copy constructor\n";
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		_type = other._type;
	return *this;
	std::cout << ">>> Animal copy assignment operator\n";
}

// Destructor
Animal::~Animal() {
	std::cout << ">>> Animal class destructor\n";
}

// Public methods
void Animal::makeSound( void ) const {
	std::cout << B_YELLOW << "🐒 Making a general animal sound!\n" << RESET;
}

std::string	Animal::getType( void ) const {
	return _type;
}
