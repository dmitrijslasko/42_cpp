#include "Dog.hpp"
#include "Brain.hpp"

// Constructor (default)
Dog::Dog() : brain_(new Brain()) {
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
		brain_ = new Brain(*other.brain_); // 👈 Deep copy
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other) {
	std::cout << ">> 🐶 Dog copy assignment operator\n";
	if (this != &other) {
		type_ = other.type_;
		*brain_ = *other.brain_;
	}
	return *this;
}

// Destructor
Dog::~Dog() {
	std::cout << ">> 🐶 Dog class destructor\n";
	delete brain_;
}

// Public methods
void Dog::makeSound( void ) const {
	std::cout << B_GREEN << "🐶 Making a dog sound. Woof woof!" << RESET << std::endl;
}


void Dog::addNewIdea(std::string idea) {
	this->brain_->setIdea(this->getIdeaCount(), idea);
}

void Dog::printAllIdeas() const {
	for (int i = 0; i < IDEAS_COUNT; i++) {
		std::string idea = this->brain_->getIdea(i);
		if (idea == "")
			break ;
		std::cout << idea << std::endl;
	}
}

int Dog::getIdeaCount() const {
	return this->brain_->getIdeaCount();
	}
