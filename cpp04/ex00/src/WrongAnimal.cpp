#include "WrongAnimal.hpp"

// Constructor (default)
WrongAnimal::WrongAnimal() {
	std::cout << ">>> 🐒 WrongAnimal default constructor\n";
	type_ = "Generic WrongAnimal";
}

//// Constructor (parameterized)
//WrongAnimal::WrongAnimal(std::string type) : _type(type) {
//	std::cout << ">>> WrongAnimal parameterized constructor\n";
//}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_)	{
	std::cout << ">>> 🐒 WrongAnimal copy constructor\n";
}

// Copy assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << ">>> 🐒 WrongAnimal copy assignment operator\n";
	if (this != &other)
		type_ = other.type_;
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << ">>> 🐒 WrongAnimal class destructor\n";
}

// Public methods
void WrongAnimal::makeSound( void ) const {
	std::cout << B_YELLOW << "🐒 Making a generic WrongAnimal sound. He he!" << RESET << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return type_;
}
