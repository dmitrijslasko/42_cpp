#include <iostream>

#include "Bureaucrat.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		printSeparator();
		try {
			Bureaucrat b("Mr Smith", 150);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat c("Mr Johns", 90);
		c.signForm();
		std::cout << c << std::endl;
	}
	printSeparator();
	return 0;
}
