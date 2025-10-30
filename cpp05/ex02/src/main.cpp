#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		ShrubberyCreationForm f;
		Bureaucrat b = Bureaucrat("Tom", 1);
		try {
			f.beSigned(b);
			f.beExecuted(b);
		}
		catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
		}

		printSeparator();
	}
	std::cout << "✅ All tests finished!\n";
	return 0;
}
