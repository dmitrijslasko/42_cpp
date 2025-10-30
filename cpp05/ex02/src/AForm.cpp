#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define EMOJI_CHAR "📝"

void printFullInfo(const AForm &form) {
	std::cout << " name_: \"" << form.getName();;
	std::cout << "\"; isSigned_: " << form.getIsSigned();
	std::cout << "\"; gradeToSign_: " << form.getGradeToSign();
	std::cout << "\"; gradeToExecute_: " << form.getGradeToExecute();
	std::cout << std::endl;
}

// Constructor (default)
AForm::AForm()
	: name_("<Unnamed>"),
	isSigned_(false),
	gradeToSign_(1),
	gradeToExecute_(1)
	{
	std::cout << ">>> " << EMOJI_CHAR << " ✅ AForm DEFAULT constructor.";
	printFullInfo(*this);
}

// Constructor (parameterized)
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
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
	std::cout << ">>> " << EMOJI_CHAR << " ✅ AForm PARAMETERIZED constructor.";
	printFullInfo(*this);
}

// Copy constructor
AForm::AForm(const AForm &other)
	: name_(other.name_),
	isSigned_(other.isSigned_),
	gradeToSign_(other.gradeToSign_),
	gradeToExecute_(other.gradeToExecute_)
{
	std::cout << ">>> " << EMOJI_CHAR << " ✅ AForm COPY constructor.";
	printFullInfo(*this);
}

// Copy assignment operator
AForm &AForm::operator=(const AForm &other) {
	std::cout << ">>> " << EMOJI_CHAR << " AForm copy assignment operator.\n";
	if (this != &other) {
		isSigned_ = other.isSigned_;
	}
	return *this;
}

// Destructor
AForm::~AForm() {
	std::cout << ">>> " << EMOJI_CHAR << " ❌ AForm destructor.";
	printFullInfo(*this);
}

std::string AForm::getName( void ) const {
	return name_;
}

bool AForm::getIsSigned( void ) const {
	return isSigned_;
}

int AForm::getGradeToSign( void ) const {
	return gradeToSign_;
}

int AForm::getGradeToExecute( void ) const {
	return gradeToExecute_;
}

std::ostream &operator<<(std::ostream &os, AForm const &other) {
	os << other.getName();
	os << ", isSigned: ";
	os << other.getIsSigned();
	os << "; Access grades: ";
	os << " [" << other.getGradeToSign();
	os << ", "<< other.getGradeToExecute() << "]";
	return (os);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
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

void AForm::beExecuted(const Bureaucrat &bureaucrat) {
	(void) bureaucrat;
	std::cout << "FORM IS NOW EXECUTED!" << std::endl;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() {
	return
	"\033[31m🔴 AForm: EXCEPTION: Grade too high!\033[0m";  // 🔴 red text
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "\033[31m🔴 AForm: EXCEPTION: Grade too low!\033[0m";   // 🔴 red text
}
