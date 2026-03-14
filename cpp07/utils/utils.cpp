#include <string>
#include <iostream>

#include "colors.hpp"
#include "utils.hpp"

#define SEPARATOR_CLR	GREEN
#define SEPARATOR_WIDTH	80
#define SEPARATOR_CHAR	'='

void	setColor (const std::string color) {
	std::cout << color;
}

void	resetColor ( void ) {
	std::cout << RESET;
}

void printSeparator(void)
{
    setColor(SEPARATOR_CLR);

    for (int i = 0; i < SEPARATOR_WIDTH; ++i)
        std::cout << SEPARATOR_CHAR;

    resetColor();
    std::cout << std::endl;
}

void printSeparator(std::string color)
{
    setColor(color);

    for (int i = 0; i < SEPARATOR_WIDTH; ++i)
        std::cout << SEPARATOR_CHAR;

    resetColor();
    std::cout << std::endl;
}
void	printTestHeader(std::string test_name)
{
	waitForInput();
	clearTerminal();
	static int test_number = 1;
	printSeparator();
	std::cout << std::endl;
	setColor(YELLOW);
	std::cout << "🌕 (" << test_number++ << ") " << test_name << std::endl;
	resetColor();
}

void expect(const std::string &msg) {
	setColor(YELLOW);
	std::cout << "Expected: " << msg << std::endl;
	resetColor();
	waitForInput();
}

void waitForInput() {
	std::string input;
	std::cout << "Press ENTER to continue...";
	std::getline(std::cin, input);
}

void clearTerminal() {
	std::cout << "\033[2J\033[H";
}
