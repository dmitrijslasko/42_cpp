#include "Animal.hpp"

// Constructor (default)
Animal::Animal() {
	std::cout << ">>> 🐒 Animal default constructor\n";
	_type = "Generic animal";
}

//// Constructor (parameterized)
//Animal::Animal(std::string type) : _type(type) {
//	std::cout << ">>> Animal parameterized constructor\n";
//}

// Copy constructor
Animal::Animal(const Animal &other) : _type(other._type)	{
	std::cout << ">>> 🐒 Animal copy constructor\n";
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other) {
	std::cout << ">>> 🐒 Animal copy assignment operator\n";
	if (this != &other)
		_type = other._type;
	return *this;
}

// Destructor
Animal::~Animal() {
	std::cout << ">>> 🐒 Animal class destructor\n";
}

// Public methods
void Animal::makeSound( void ) const {
	std::cout << B_YELLOW << "🐒 Making a generic animal sound. He he!" << RESET << std::endl;
}

std::string	Animal::getType( void ) const {
	return _type;
}
