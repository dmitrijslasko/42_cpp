#include <iostream>
#include "Bureaucrat.hpp"
#include "utils.hpp"

int	main ( void ) {

	{
		printTestHeader("Testing DEFAULT constructor");
		try {
			Bureaucrat a;
			std::cout << a << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
		{
		printTestHeader("Testing PARAMETERIZED constructor");
		try {
			Bureaucrat a("Mr Important", 100);
			std::cout << a << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Testing PARAMETERIZED constructor with a grade too high (<1)");
		try {
			Bureaucrat b("Mr Smith", -10);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Testing PARAMETERIZED constructor with a grade too low (>150)");
		try {
			Bureaucrat b("Mr Smith", 160);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printTestHeader("Testing INCREMENTS that go a bit too far (below 1)");
		const int COUNT = 5;
		Bureaucrat bureaucrats[COUNT];
		for (int i = 0; i < COUNT; i++) {
			try {
			bureaucrats[i].incrementGrade(i * 50);
			std::cout << bureaucrats[i] << std::endl;
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	{
		printTestHeader("Testing DECREMENTS that go a bit too far (above 150)");
		const int COUNT = 5;
		Bureaucrat bureaucrats[COUNT];
		for (int i = 0; i < COUNT; i++) {
			try {
			bureaucrats[i].decrementGrade(i * 50);
			std::cout << bureaucrats[i] << std::endl;
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	printSeparator();
	return 0;
}
