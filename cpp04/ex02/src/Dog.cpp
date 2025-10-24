#include "Dog.hpp"
#include "Brain.hpp"

// Constructor (default)
Dog::Dog() : _brain(new Brain()) {
	std::cout << ">> 🐶 Dog default constructor\n";
	_type = "Dog";
}

//// Constructor (parameterized)
//Dog::Dog(std::string type) : Animal(type) {
//	std::cout << ">> Dog parameterized constructor\n";
//}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << ">> 🐶 Dog copy constructor\n";
		_brain = new Brain(*other._brain); // 👈 Deep copy
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other) {
	std::cout << ">> 🐶 Dog copy assignment operator\n";
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

// Destructor
Dog::~Dog() {
	std::cout << ">> 🐶 Dog class destructor\n";
	delete _brain;
}

// Public methods
void Dog::makeSound( void ) const {
	std::cout << B_GREEN << "🐶 Making a dog sound. Woof woof!" << RESET << std::endl;
}


void Dog::addNewIdea(std::string idea) {
	this->_brain->setIdea(0, idea);
}

void Dog::printAllIdeas() const {
	for (int i = 0; i < IDEAS_COUNT; i++) {
		std::string idea = this->_brain->getIdea(i);
		if (idea == "")
			break ;
		std::cout << idea << std::endl;
	}
}
