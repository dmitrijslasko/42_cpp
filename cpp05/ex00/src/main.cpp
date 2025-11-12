#include <iostream>
#include "Bureaucrat.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		printTestHeader("Testing DEFAULT constructor");
		expect("name = '<Unnamed> Bureaucrat', grade = 150");
		try {
			Bureaucrat a;
			std::cout << a << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		printSeparator();
	}
	{
		printTestHeader("Testing PARAMETERIZED constructor");
		expect("name = 'Mr Important', grade = 100");
		try {
			Bureaucrat a("Mr Important", 100);
			std::cout << a << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		printSeparator();
	}
	{
		printTestHeader("Testing PARAMETERIZED constructor with a grade too high (<1)");
		expect("Exception: Grade too high.");
		try {
			Bureaucrat b("Mr Smith", -10);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		printSeparator();
	}
	{
		printTestHeader("Testing PARAMETERIZED constructor with a grade too low (>150)");
		try {
			expect("Exception: Grade too low.");
			Bureaucrat b("Mr Smith", 160);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		printSeparator();
	}
	{
		printTestHeader("Testing INCREMENTS that go too high (below 1)");
		expect("Incremented grade for first 3. Exception: grade too high for 2 next.");
		const int COUNT = 5;
		Bureaucrat bureaucrats[COUNT];
		for (int i = 0; i < COUNT; i++) {
			try {
				std::cout << "[" << i + 1<< "] ";
				bureaucrats[i].incrementGrade(10 + i * 50);
				std::cout << bureaucrats[i] << std::endl;
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		printSeparator();
	}
	{
		printTestHeader("Testing DECREMENTS that go too low (above 150)");
		expect("Decremented grade for first 3. Exception: grade too low for 2 next.");
		const int COUNT = 5;
		Bureaucrat bureaucrats[COUNT];
		bureaucrats[0].incrementGrade(149);
		bureaucrats[1].incrementGrade(149);
		bureaucrats[2].incrementGrade(149);
		for (int i = 0; i < COUNT; i++) {
			try {
				std::cout << "[" << i + 1<< "] ";
				bureaucrats[i].decrementGrade(10 + i * 50);
				// std::cout << bureaucrats[i] << std::endl;
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		printSeparator();
	}
	printSeparator();
	std::cout << "✅ All tests finished!\n";
	return 0;
}
