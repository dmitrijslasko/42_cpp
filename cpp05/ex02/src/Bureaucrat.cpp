#include "Bureaucrat.hpp"
#include "AForm.hpp"

void printFullInfo(const Bureaucrat &bureaucrat) {
	std::cout << " name_: \"" << bureaucrat.getName();;
	std::cout << "\"; grade_: " << bureaucrat.getGrade();
	std::cout << std::endl;
}

// Constructor (default)
Bureaucrat::Bureaucrat() : name_("<Unnamed> Bureaucrat"), grade_(Bureaucrat::LOWEST_GRADE) {
	std::cout << ">>> 👔 ✅ Bureaucrat DEFAULT constructor.";
	printFullInfo(*this);
}

// Constructor (parameterized)
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade) {
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw GradeTooHighException();
	else if (grade < Bureaucrat::HIGHEST_GRADE)
		throw GradeTooLowException();
	std::cout << ">>> 👔 ✅ Bureaucrat PARAMETERIZED constructor.";
	printFullInfo(*this);int signForm( void );
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name_(other.name_), grade_(other.grade_)
{
	std::cout << ">>> 👔 ✅ Bureaucrat COPY constructor.";
	printFullInfo(*this);
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
	printFullInfo(*this);
}

std::string Bureaucrat::getName( void ) const {
	return name_;
}

int	Bureaucrat::getGrade( void ) const {
	return grade_;
}

void Bureaucrat::incrementGrade( int amount ) {
	int newGrade = grade_ - amount;
	if (newGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	std::cout << "➕ Grade for " << name_ << " incremented: " << grade_ << " --> " << newGrade;
	std::cout << std::endl;
	grade_ = newGrade;
}

void Bureaucrat::decrementGrade( int amount ) {
	int newGrade = grade_ + amount;
	if (newGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "➖ Grade for " << name_ << " decremented: " << grade_ << " --> " << newGrade;
	std::cout << std::endl;
	grade_ = newGrade;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (os);
}

int Bureaucrat::signForm( AForm &form ) {
	try {
		form.beSigned(*this);
		setColor(GREEN);
		std::cout << "✅ Bureaucrat '" << this->getName() << "' signed '" << form.getName() << "'";
		resetColor();
		std::cout << std::endl;
		return 0;
	}
	catch (const std::exception &e) {
		setColor(RED);
		std::cout << "❌ Bureaucrat '" << this->getName() << "' could not sign " << form.getName() << " because " << e.what();
		resetColor();
		std::cout << std::endl;
		return 1;
	}
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "\033[31m🔴 Bureaucrat: EXCEPTION: Grade too high!\033[0m";  // 🔴 red text
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "\033[31m🔴 Bureaucrat: EXCEPTION: Grade too low!\033[0m";   // 🔴 red text
}
