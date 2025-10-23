#include "WrongCat.hpp"

// Constructor (default)
WrongCat::WrongCat() {
	std::cout << ">> 🐱 WrongCat default constructor\n";
	_type = "WrongCat";
}

//// Constructor (parameterized)
//WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
//	std::cout << ">> WrongCat parameterized constructor\n";
//}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << ">> 🐱 WrongCat copy constructor\n";
}

// Copy assignment operator
WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		_type = other._type;
	return *this;
	std::cout << ">> 🐱 WrongCat copy assignment operator\n";
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << ">> 🐱 WrongCat class destructor\n";
}

// Public methods
void WrongCat::makeSound( void ) const {
	std::cout << B_MAGENTA << "🐱 Making a WrongCat sound. Meow meow!" << RESET << std::endl;
}
