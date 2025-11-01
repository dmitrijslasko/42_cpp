#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>    // for time()

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), target_("default_target") {
	std::cout << "RobotomyRequestForm DEFAULT constructor.\n";
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), target_(target) {
	std::cout << "RobotomyRequestForm constructed for target: " << target << "\n";
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target_(other.target_) {
	std::cout << "RobotomyRequestForm copy constructed\n";
}

// Copy assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	std::cout << "RobotomyRequestForm assigned\n";
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor\n";
}

void 	RobotomyRequestForm::setTarget(const std::string target) {
	target_ = target;
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const {

	(void) bureaucrat;

	std::cout << "🛠️  BZZZZZZ... drilling noises..." << std::endl;
	system("aplay ./assets/drill.wav > /dev/null 2>&1");
	std::srand(std::time(NULL));

	if (std::rand() % 2) {
		setColor(B_GREEN);
        std::cout << "✅ " << this->target_<< " has been robotomized successfully!" << std::endl;
    } else {
		setColor(B_RED);
        std::cout << "❌ Robotomy failed for " << this->target_ << "..." << std::endl;
    }
	resetColor();
}
