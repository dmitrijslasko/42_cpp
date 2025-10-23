#include "Brain.hpp"

// Constructor (default)
Brain::Brain() {
	std::cout << ">> 🧠 Brain default constructor\n";
}

//// Constructor (parameterized)
//Brain::Brain(std::string type) : Animal(type) {
//	std::cout << ">> Brain parameterized constructor\n";
//}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << ">> 🧠 Brain copy constructor\n";
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[100];
	}
}

// Copy assignment operator
Brain &Brain::operator=(const Brain &other) {
	std::cout << ">> 🧠 Brain copy assignment operator\n";
	if (this != &other)
	{
		 for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
	}
	return *this;
}

// Destructor
Brain::~Brain() {
	std::cout << ">> 🧠 Brain class destructor\n";
}
