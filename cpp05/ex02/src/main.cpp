#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

int	main ( void ) {
	//AForm f = ShrubberyCreationForm();
	ShrubberyCreationForm f;
	Bureaucrat b = Bureaucrat("Tom", 150);

	f.beSigned(b);
	printSeparator();
	std::cout << "✅ All tests finished!\n";
	return 0;
}
