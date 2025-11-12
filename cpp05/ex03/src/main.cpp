#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

int main( void ) {
	clearTerminal();
	{
		printTestHeader("Robotomy request - SUCCESS");
		expect("Intern creates a robotomy request form.");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("robotomy request", "Bender");
		delete form;
		printSeparator();
	}
	{
		printTestHeader("Shrubbery creation - SUCCESS");
		expect("Intern creates a shrubbery creation form.");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("shrubbery creation", "Oak");
		delete form;
		printSeparator();
	}
		{
		printTestHeader("Presidential pardon - SUCCESS");
		expect("Intern creates a presidential pardon form.");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("presidential pardon", "Mister");
		delete form;
		printSeparator();
	}
	{
		printTestHeader("Unknown form - FAIL");
		expect("Intern fails to find a respective form.");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("unknown form", "Target");
		delete form;
		printSeparator();
	}
	printSeparator();
	std::cout << "✅ All tests finished!\n";
	return 0;
}
