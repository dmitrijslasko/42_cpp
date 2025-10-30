#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils.hpp"

int	main ( void ) {

	{
		printTestHeader("Form: Testing DEFAULT constructor");
		expect("name = '<Unnamed> Form', isSigned = false, gradeToSign = 1, gradeToExec = 1");
		try {
			Form f;
			std::cout << f << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Form: Testing PARAMETERIZED constructor");
		expect("name = '<Unnamed> Form', isSigned = false, gradeToSign = 150, gradeToExec = 150");
		try {
			Form f("FORM 1", 150, 150);
			std::cout << f << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Form: Testing PARAMETERIZED constructor and beSigned() - SUCCESS");
		expect("name = '<Unnamed> Form', isSigned = false, gradeToSign = 50, gradeToExec = 50");
		Form f("Very Important Form", 50, 50);
		Bureaucrat b("Bob", 10);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		try {
			f.beSigned(b);
			std::cout << f << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Form: Testing PARAMETERIZED constructor and beSigned() - FAIL");
		expect("name = '<Unnamed> Form', isSigned = false, gradeToSign = 50, gradeToExec = 50");
		Form f("Very Important Form", 50, 50);
		Bureaucrat b("Bob", 70);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		try {
			f.beSigned(b);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Form: Testing PARAMETERIZED constructor and signForm() - SUCCESS");
		expect("name = '<Unnamed> Form', isSigned = false, gradeToSign = 50, gradeToExec = 50");
		Form f("Very Important Form", 50, 50);
		Bureaucrat b("Bob", 40);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		try {
			b.signForm(f);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Form: Testing PARAMETERIZED constructor and signForm() - FAIL");
		expect("name = '<Unnamed> Form', isSigned = false, gradeToSign = 50, gradeToExec = 50");
		Form f("Very Important Form", 50, 50);
		Bureaucrat b("Bob", 70);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		try {
			b.signForm(f);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	printSeparator();
	std::cout << "✅ All tests finished!\n";
	return 0;
}
