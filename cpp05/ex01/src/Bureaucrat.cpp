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

std::string Bureaucrat::getName( void ) const {
	return name_;
}

int	Bureaucrat::getGrade( void ) const {
	return grade_;
}

void Bureaucrat::incrementGrade( int amount ) {
	grade_ -= amount;
}

void Bureaucrat::decrementGrade( int amount ) {
	grade_ += amount;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

int Bureaucrat::signForm( void ) {
	std::cout << "<bureaucrat> signed <form>" << std::endl;
	return 1;
}
