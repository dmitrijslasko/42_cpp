#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>    // for time()

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE), target_("default_target") {
	std::cout << "PresidentialPardonForm DEFAULT constructor.\n";
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE), target_(target) {
	std::cout << "PresidentialPardonForm constructed for target: " << target << "\n";
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target_(other.target_) {
	std::cout << "PresidentialPardonForm copy constructed\n";
}

// Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	std::cout << "PresidentialPardonForm assigned\n";
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor\n";
}

void 	PresidentialPardonForm::setTarget(const std::string target) {
	target_ = target;
}

void PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const {

	(void) bureaucrat;

	setColor(B_GREEN);
	std::cout << "✅ " << target_<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	resetColor();
}

