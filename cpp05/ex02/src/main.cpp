#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		printTestHeader("ShrubberyCreation Form test - success");
		expect("Success: bureaucrat's grade is sufficient to sign the form.");
		printSeparator();
		ShrubberyCreationForm shrub("garden");
		AForm &form = shrub;
		Bureaucrat b = Bureaucrat("SuccessTom", 1);
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
		printTestHeader("ShrubberyCreation Form test - fail");
		expect("Fail: bureaucrat's grade is not sufficient to sign the form.");
		printSeparator();
		ShrubberyCreationForm shrub("garden");
		AForm &form = shrub;
		Bureaucrat b = Bureaucrat("FailTom", 150);
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
		printTestHeader("ShrubberyCreation Form test - fail");
		expect("Success on signing, fail on execution.");
		printSeparator();
		ShrubberyCreationForm shrub("garden");
		AForm &form = shrub;
		Bureaucrat b = Bureaucrat("FailTom", 140);
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
		printTestHeader("RobotomyRequestForm test - success/fail depends on random");
		expect("Result is decided in the runtime.");
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
		printTestHeader("PresidentialPardonForm test - success");
		expect("Success: bureaucrat's grade is sufficient to sign the form.");
		printSeparator();
		PresidentialPardonForm f;
		Bureaucrat b = Bureaucrat("Mr Success", 3);
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
	{
		printTestHeader("PresidentialPardonForm test - fail");
		expect("Fail: bureaucrat's grade is not sufficient to sign the form.");
		printSeparator();
		PresidentialPardonForm f;
		Bureaucrat b = Bureaucrat("Mr Fail", 120);
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
	{
		printTestHeader("PresidentialPardonForm test - success");
		expect("Success on signing, fail on execution.");
		printSeparator();
		PresidentialPardonForm f;
		Bureaucrat b = Bureaucrat("Mr Success", 20);
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
