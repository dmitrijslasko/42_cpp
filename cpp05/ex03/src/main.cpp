#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

int main( void ) {
	{
		printTestHeader("Robotomy request - SUCCESS");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("robotomy request", "Bender");
		delete form;
	}
	{
		printTestHeader("Shrubbery request - SUCCESS");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("shrubbery creation", "Oak");
		delete form;
	}
		{
		printTestHeader("Presidential pardon - SUCCESS");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("presidential pardon", "Mister");
		delete form;
	}
	{
		printTestHeader("Unknown form - FAIL");
		printSeparator();
		Intern intern;
		AForm *form;

		form = intern.makeForm("unknown form", "Target");
		delete form;
	}
	printSeparator();
	std::cout << "✅ All tests finished!\n";
	return 0;
}
