#include "Brain.hpp"

// Constructor (default)
Brain::Brain() {
	std::cout << ">> 🧠 Brain default constructor\n";
	_idea_count = 0;
}

//// Constructor (parameterized)
//Brain::Brain(std::string type) : Animal(type) {
//	std::cout << ">> Brain parameterized constructor\n";
//}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << ">> 🧠 Brain copy constructor\n";
	for (int i = 0; i < IDEAS_COUNT; i++)
		_ideas[i] = other._ideas[i];
}

// Copy assignment operator
Brain &Brain::operator=(const Brain &other) {
	std::cout << ">> 🧠 Brain copy assignment operator\n";
	if (this != &other)
	{
		 for (int i = 0; i < IDEAS_COUNT; i++)
            _ideas[i] = other._ideas[i];
	}
	return *this;
}

// Destructor
Brain::~Brain() {
	std::cout << ">> 🧠 Brain class destructor\n";
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index > IDEAS_COUNT) {
		std::cout << "Not a good index!" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index > IDEAS_COUNT) {
		std::cout << "Not a good index!" << std::endl;
		return "NOT A GOOD INDEX";
	}
	return _ideas[index];
}

