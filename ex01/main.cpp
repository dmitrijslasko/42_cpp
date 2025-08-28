#include <iostream>
#include <cctype>

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

#include "settings.h"

std::string printColor(std::string str, std::string color);

std::string trim(const std::string& str) {

	// trim preceding spaces
    std::string::const_iterator start = str.begin();
    while (start != str.end() && std::isspace(*start))
        start++;

	// trim trailing spaces
    std::string::const_iterator end = str.end();
	end--;
	while (end != start && std::isspace(*end))
        end--;

    return std::string(start, end + 1);
}

std::string promptInput(const std::string& prompt) {
    std::string input;

	while (input.empty()) {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::cout << "\nEOF detected, quitting the phonebook..." << std::endl;
			exit(0);
		}
        input = trim(input);
		if (input.empty())
			std::cout << printColor("Empty input not allowed! Input text to proceed.", B_RED) << std::endl;
    }
    return input;
}

void	printLineBreaks(const int count, const char *color)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << color;
		for (int i = 0; i < LINE_BREAK_LEN; i++)
			std::cout << LINE_BREAK_CHAR;
		std::cout << RESET;
		std::cout << std::endl;
	}
}

std::string printColor(std::string str, std::string color)
{
	return color + str + RESET;
}

void	printInstructions(void)
{
	printLineBreaks(1, MAGENTA);
	std::cout 	<< ASCII_LOGO;
	
	printLineBreaks(1, MAGENTA);
	std::cout << printColor(LINE1_TEXT, LINE1_CLR) << RESET << std::endl;
	std::cout << "👤 " << printColor(CMD1, CMD_CLR) << printColor(CMD1_PROMPT, CMD_PROMPT_CLR) << std::endl;
	std::cout << "🔍 " << printColor(CMD2, CMD_CLR) << printColor(CMD2_PROMPT, CMD_PROMPT_CLR) << std::endl;
	// std::cout << "🙏 " << printColor(CMD3, CMD_CLR) << printColor(CMD3_PROMPT, CMD_PROMPT_CLR) << std::endl;
	std::cout << "🚪 " << printColor(CMD4, CMD_CLR) << printColor(CMD4_PROMPT, CMD_PROMPT_CLR) << std::endl;
	printLineBreaks(1, LINE_BREAK_COLOR);
}

int	main(void) {

	PhoneBook 	phonebook;
	std::string	command;

	// print out instructions
	printInstructions();

	while (true) {

		// print prompt and take input
		std::cout << printColor(PROMPT_TEXT, PROMPT_CLR);
		std::getline(std::cin, command);
		
		// std::cin >> command; does not work here because we need whole line not separate words

		// handle commands
		if (command == CMD1)
			phonebook.add();
		else if (command == CMD2)
			phonebook.search();
		// else if (command == CMD3)
		// 	printInstructions();
		else if (command == CMD4)
		{
			if (phonebook.quit())
			{
				std::cout << printColor(EXIT_TEXT, EXIT_TEXT_CLR) << std::endl;
				break ;
			}
		}
		else if (std::cin.eof())
		{
			std::cout << "\nEOF detected, quitting the phonebook..." << std::endl;
			return (0);
		}
		else
			std::cout << printColor(BAD_PROMPT_TEXT, BAD_PROMPT_CLR) << std::endl;
	}
	return 0;
}