#include "Cat.hpp"

// Constructor (default)
Cat::Cat() {
	std::cout << ">>> Cat default constructor\n";
}

// Constructor (parameterized)
Cat::Cat(std::string type) : Animal(type) {
	std::cout << ">>> Cat parameterized constructor\n";
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << ">>> Cat copy constructor\n";
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		_type = other._type;
	return *this;
	std::cout << ">>> Cat copy assignment operator\n";
}

// Destructor
Cat::~Cat() {
	std::cout << ">>> Cat class destructor\n";
}

// Public methods
void Cat::makeSound( void ) {
	std::cout << B_MAGENTA << "🐱 Making a cat sound. Meow meow!\n" << RESET;
}
