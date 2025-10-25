#include "Cat.hpp"
#include "Brain.hpp"

// Constructor (default)
Cat::Cat() : brain_(new Brain()) {
	std::cout << ">> 🐱 Cat default constructor\n";
	type_ = "Cat";
}

//// Constructor (parameterized)
//Cat::Cat(std::string type) : Animal(type) {
//	std::cout << ">> Cat parameterized constructor\n";
//}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << ">> 🐱 Cat copy constructor\n";
	brain_ = new Brain(*other.brain_); // 👈 Deep copy
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		type_ = other.type_;
		*brain_ = *other.brain_;
	}
	return *this;
	std::cout << ">> 🐱 Cat copy assignment operator\n";
}

// Destructor
Cat::~Cat() {
	std::cout << ">> 🐱 Cat class destructor\n";
	delete brain_;
}

// Public methods
void Cat::makeSound( void ) const {
	std::cout << B_MAGENTA << "🐱 Making a cat sound. Meow meow!" << RESET << std::endl;
}

