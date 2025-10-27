#include "Bureaucrat.hpp"

// Constructor (default)
Bureaucrat::Bureaucrat() : name_("Generic Bureaucrat"), grade_(Bureaucrat::LOWEST_GRADE) {
	std::cout << ">>> 👔 ✅ Bureaucrat DEFAULT constructor.";
	std::cout << " name_: \"" << name_;
	std::cout << "\"; grade_: " << grade_;
	std::cout << std::endl;
}

// Constructor (parameterized)
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << ">>> 👔 ✅ Bureaucrat PARAMETERIZED constructor.";
	std::cout << " name_: \"" << name_;
	std::cout << "\"; grade_: " << grade_;
	std::cout << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name_(other.name_), grade_(other.grade_)
{
	std::cout << ">>> 👔 ✅ Bureaucrat COPY constructor.";
	std::cout << " name_: \"" << name_;
	std::cout << "\"; grade_: " << grade_;
	std::cout << std::endl;
}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << ">>> 👔 Bureaucrat copy assignment operator.\n";
	if (this != &other) {
		grade_ = other.grade_;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << ">>> 👔 ❌ Bureaucrat destructor.";
	std::cout << " name_: \"" << name_;
	std::cout << "\"; grade_: " << grade_;
	std::cout << std::endl;
}

std::string Bureaucrat::getName( void ) {
	return name_;
}

int	Bureaucrat::getGrade( void ) {
	return grade_;
}

//// Pre-increment
//Bureaucrat& Bureaucrat::operator++() {
//	grade_ -= 1;        // smallest epsilon step
//	return *this;       // return updated object
//}

//// Post-increment
//Bureaucrat Bureaucrat::operator++(int) {
//	Bureaucrat temp(*this);  // make a copy of the current state
//	grade_ -= 1;        // increment this object
//	return temp;        // return the old value
//}

//// Pre-decrement
//Bureaucrat& Bureaucrat::operator--() {
//	grade_ += 1;
//	return *this;
//}

//// Post-decrement
//Bureaucrat Bureaucrat::operator--(int) {
//	Bureaucrat temp(*this);
//	grade_ += 1;
//	return temp;
//}

void Bureaucrat::increaseGrade( int amount ) {
	grade_ -= amount;
}

void Bureaucrat::decreaseGrade( int amount ) {
	grade_ += amount;
}

