#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		printTestHeader("ShrubberyCreation Form test");
		printSeparator();
		ShrubberyCreationForm shrub("garden");
		AForm &form = shrub;
		Bureaucrat b = Bureaucrat("Tom", 1);
		try {
			form.beSigned(b);
			shrub.setTarget("tests");
			form.execute(b);
		}
		catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("RobotomyRequestForm test");
		printSeparator();
		RobotomyRequestForm f;
		Bureaucrat b = Bureaucrat("Driller", 1);
		try {
			f.beSigned(b);
			f.setTarget("test_target");
			f.execute(b);
		}
		catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("PresidentialPardonForm test");
		printSeparator();
		PresidentialPardonForm f;
		Bureaucrat b = Bureaucrat("Mr President", 20);
		try {
			f.beSigned(b);
			f.setTarget("test_person");
			f.setIsSigned(false);
			f.execute(b);
		}
		catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
		}
	}
	printSeparator();
	std::cout << "✅ All tests finished!\n";
	return 0;
}
