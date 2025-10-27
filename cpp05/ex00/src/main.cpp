#include <iostream>
#include "Bureaucrat.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		printSeparator();
		try {
			Bureaucrat b("Alice", 200);
			b.increaseGrade(5);
			b.decreaseGrade(10);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat c("Mr Johns", 90);
		std::cout << c.getGrade() << std::endl;
	}
	printSeparator();
	return 0;
}
