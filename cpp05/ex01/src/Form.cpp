#include "Form.hpp"
#include "Bureaucrat.hpp"

#define EMOJI_CHAR "📝"

void printFullInfo(const Form &form) {
	std::cout << " name_: \"" << form.getName();;
	std::cout << "\"; isSigned_: " << form.getIsSigned();
	std::cout << "\"; gradeToSign_: " << form.getGradeToSign();
	std::cout << "\"; gradeToExecute_: " << form.getGradeToExecute();
	std::cout << std::endl;
}

// Constructor (default)
Form::Form()
	: name_("<Unnamed>"),
	isSigned_(false),
	gradeToSign_(1),
	gradeToExecute_(1)
	{
	std::cout << ">>> " << EMOJI_CHAR << " ✅ Form DEFAULT constructor.";
	printFullInfo(*this);
}

// Constructor (parameterized)
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name_(name),
	isSigned_(false),
	gradeToSign_(gradeToSign),
	gradeToExecute_(gradeToExecute)
	{
	if (gradeToSign > 150)
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooHighException();
	if (gradeToSign < 1)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooLowException();
	std::cout << ">>> " << EMOJI_CHAR << " ✅ Form PARAMETERIZED constructor.";
	printFullInfo(*this);
}

// Copy constructor
Form::Form(const Form &other)
	: name_(other.name_),
	isSigned_(other.isSigned_),
	gradeToSign_(other.gradeToSign_),
	gradeToExecute_(other.gradeToExecute_)
{
	std::cout << ">>> " << EMOJI_CHAR << " ✅ Form COPY constructor.";
	printFullInfo(*this);
}

// Copy assignment operator
Form &Form::operator=(const Form &other) {
	std::cout << ">>> " << EMOJI_CHAR << " Form copy assignment operator.\n";
	if (this != &other) {
		isSigned_ = other.isSigned_;
	}
	return *this;
}

// Destructor
Form::~Form() {
	std::cout << ">>> " << EMOJI_CHAR << " ❌ Form destructor.";
	printFullInfo(*this);
}

std::string Form::getName( void ) const {
	return name_;
}

bool Form::getIsSigned( void ) const {
	return isSigned_;
}

int Form::getGradeToSign( void ) const {
	return gradeToSign_;
}

int Form::getGradeToExecute( void ) const {
	return gradeToExecute_;
}

std::ostream &operator<<(std::ostream &os, Form const &other) {
	os << other.getName();
	os << ", isSigned: ";
	os << other.getIsSigned();
	os << "; Access grades: ";
	os << "[" << other.getGradeToSign();
	os << ", "<< other.getGradeToExecute() << "]";
	return (os);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->isSigned_ = 1;
	setColor(GREEN);
	std::cout << "✅ The form '" << this->getName() << "' with gradeToSign " << this->getGradeToSign() << " is now signed by: ";
	std::cout << bureaucrat.getName() << " [Grade: ";
	std::cout << bureaucrat.getGrade() << "]";
	resetColor();
	std::cout << std::endl;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
	return
	"\033[31m🔴 Form: EXCEPTION: Grade too high!\033[0m";  // 🔴 red text
}

const char *Form::GradeTooLowException::what() const throw() {
	return "\033[31m🔴 Form: EXCEPTION: Grade too low!\033[0m";   // 🔴 red text
}
