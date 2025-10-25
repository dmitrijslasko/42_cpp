#include "Animal.hpp"

// Constructor (default)
Animal::Animal() {
	std::cout << ">>> 🐒 Animal default constructor\n";
	type_ = "Generic animal";
}

//// Constructor (parameterized)
//Animal::Animal(std::string type) : _type(type) {
//	std::cout << ">>> Animal parameterized constructor\n";
//}

// Copy constructor
Animal::Animal(const Animal &other) : type_(other.type_)	{
	std::cout << ">>> 🐒 Animal copy constructor\n";
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other) {
	std::cout << ">>> 🐒 Animal copy assignment operator\n";
	if (this != &other)
		type_ = other.type_;
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
	return type_;
}
