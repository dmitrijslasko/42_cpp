#include <string>
#include <iostream>

#include "colors.hpp"

#define SEPARATOR_WIDTH	70
#define SEPARATOR_CHAR	'='

void	printSeparator( void ) {
	std::string out = "";
	for (int i = 0; i < SEPARATOR_WIDTH; i++)
		out += SEPARATOR_CHAR;
	std::cout << CYAN << out << RESET << std::endl;
}
