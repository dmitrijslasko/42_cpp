#include "Form.hpp"

// Constructor (default)
Form::Form()
	: name_("Generic Form"),
	isSigned_(false),
	gradeToSign_(1);
	gradeToExecute_(1);
	{
	std::cout << ">>> 📝 ✅ Form DEFAULT constructor.";
	std::cout << " isSigned_: " << isSigned_;
	std::cout << "; gradeToSign_: " << gradeToSign_;
	std::cout << "; gradeToExecute: " << gradeToExecute_;
	std::cout << std::endl;
}

// Constructor (parameterized)
Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute)
	: name_(name),
	isSigned_(false),
	gradeToSign_(gradeToSign);
	gradeToExecute_(gradeToExecute);
	{
	std::cout << ">>> 📝 ✅ Form PARAMETERIZED constructor.";
	std::cout << " isSigned_: " << isSigned_;
	std::cout << "; gradeToSign_: " << gradeToSign_;
	std::cout << "; gradeToExecute: " << gradeToExecute_;
	std::cout << std::endl;
}

// Copy constructor
Form::Form(const Form &other)
	: name_(other.name_), grade_(other.grade_)
{
	std::cout << ">>> 📝 ✅ Form COPY constructor.";
	std::cout << " isSigned_: " << isSigned_;
	std::cout << "; gradeToSign_: " << gradeToSign_;
	std::cout << "; gradeToExecute: " << gradeToExecute_;
	std::cout << std::endl;
}

// Copy assignment operator
Form &Form::operator=(const Form &other) {
	std::cout << ">>> 📝 Form copy assignment operator.\n";
	if (this != &other) {
		name_ = other.name_;
	}
	return *this;
}

// Destructor
Form::~Form() {
	std::cout << ">>> 📝 ❌ Form destructor.";
	std::cout << " isSigned_: " << isSigned_;
	std::cout << "; gradeToSign_: " << gradeToSign_;
	std::cout << "; gradeToExecute: " << gradeToExecute_;
	std::cout << std::endl;
}

std::string Form::getName( void ) const {
	return name_;
}

std::ostream &operator<<(std::ostream &os, Form const &other) {
	os << other.getName() << std::endl;
	return (os);
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}
