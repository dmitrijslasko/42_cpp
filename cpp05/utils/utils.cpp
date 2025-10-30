#include <string>
#include <iostream>

#include "colors.hpp"

#define SEPARATOR_WIDTH	70
#define SEPARATOR_CHAR	'='

void	setColor (const std::string color) {
	std::cout << color;
}

void	resetColor ( void ) {
	std::cout << RESET;
}

void	printSeparator( void ) {
	std::string out = "";
	for (int i = 0; i < SEPARATOR_WIDTH; i++)
		out += SEPARATOR_CHAR;
	setColor(CYAN);
	std::cout << out;
	resetColor();
	std::cout << std::endl;
}

void	printTestHeader(std::string test_name)
{
	static int test_number = 1;
	printSeparator();
	setColor(YELLOW);
	std::cout << "🌕 (" << test_number++ << ") " << test_name << std::endl;
	resetColor();
}

void expect(const std::string &msg) {
	setColor(YELLOW);
	std::cout << "Expected: " << msg << std::endl;
	resetColor();
}
