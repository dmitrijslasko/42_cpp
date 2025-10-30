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

void	printTestHeader(std::string test_name)
{
	static int test_number = 1;
	printSeparator();
	std::cout << B_YELLOW;
	std::cout << "🌕 (" << test_number++ << ") " << test_name << std::endl;
	std::cout << RESET;
}

void expect(const std::string &msg) {
	std::cout << YELLOW;
	std::cout << "Expected: " << msg << std::endl;
	std::cout << RESET;
}
