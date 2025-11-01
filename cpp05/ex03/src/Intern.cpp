#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructor (default)
Intern::Intern() {
	std::cout << ">>> 👶 ✅ Intern DEFAULT constructor.\n";
}

// Copy constructor
Intern::Intern(const Intern &other) {
	std::cout << ">>> 👶 ✅ Intern COPY constructor.ņ";
	(void)other;
}

// Copy assignment operator
Intern &Intern::operator=(const Intern &other) {
	std::cout << ">>> 👶 Intern copy assignment operator.\n";
	(void)other;
	return *this;
}

// Destructor
Intern::~Intern() {
	std::cout << ">>> 👶 ❌ Intern destructor.\n";
}

// ---------- Static creator functions ----------

static AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &formTarget) {

	struct FormPair {
		const char* name;
		AForm* (*function)(std::string const &);
	};

	FormPair forms[] = {
        {"shrubbery creation",  &createShrubbery},
        {"robotomy request",    &createRobotomy},
        {"presidential pardon", &createPresidential}
    };

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i].name) {
			setColor(B_GREEN);
			std::cout << "Intern creates " << formName << "." << std::endl;
			resetColor();
			return (forms[i]).function(formTarget);
		}
	}

	setColor(B_RED);
	std::cerr << "Intern couldn't find a form called \"" << formName << "\"" << std::endl;
	resetColor();
	return NULL;
}
