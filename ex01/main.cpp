#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

#include "settings.h"

std::string printColor(std::string str, std::string color);

/* This function trims preceding and trailing spaces*/
std::string trim(const std::string& str) {
	if (str.size() == 0)
		return str;

	// trim preceding spaces
    std::string::const_iterator start = str.begin();
    while (start != str.end() && std::isspace(*start))
        start++;

	// trim trailing spaces
    std::string::const_iterator end = str.end();
	end--;
	while (end != start && std::isspace(*end))
        end--;

	if (start < end + 1)
    	return std::string(start, end + 1);

	return "";
}

std::string promptInput(const std::string& prompt) {

	const int PROMPT_WIDTH = 20;
    std::string input;

	while (input.empty()) {
		std::cout << std::left << std::setw(PROMPT_WIDTH) << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::cout << "\nEOF detected, quitting the phonebook..." << std::endl;
			exit(0);
		}
		if (TRIM_INPUTS)
			input = trim(input);
		if (input.empty())
		{
			std::cout << printColor("⚠️  Empty input not allowed! Input text to proceed.\n", B_RED) << std::endl;
			continue ;
		}

    }
    return input;
}

/* Prints a line break of specified count and color*/
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

/* Prints color text. Resets the color option at the end*/
std::string printColor(std::string str, std::string color)
{
	return color + str + RESET;
}

/* Prints color text. Does not reset the color option at the end*/
std::string printColorNoReset(std::string str, std::string color)
{
	return color + str;
}

/* Prints out phonebook usage manual*/
void	printInstructions(void)
{
	size_t	WIDTH = 20;

	printLineBreaks(1, MAGENTA);
	std::cout 	<< ASCII_LOGO;

	printLineBreaks(1, MAGENTA);
	std::cout 	<< printColor(LINE1_TEXT, LINE1_CLR) << RESET << std::endl
				<< "👤 " << std::left << std::setw(WIDTH) << printColor(CMD1, CMD_CLR) << printColor(CMD1_PROMPT, CMD_PROMPT_CLR) << std::endl
			 	<< "🔍 " << std::left << std::setw(WIDTH) << printColor(CMD2, CMD_CLR) << printColor(CMD2_PROMPT, CMD_PROMPT_CLR) << std::endl
		 		// << "🙏 " << printColor(CMD3, CMD_CLR) << printColor(CMD3_PROMPT, CMD_PROMPT_CLR) << std::endl;
				<< "🚪 " << std::left << std::setw(WIDTH) << printColor(CMD4, CMD_CLR) << printColor(CMD4_PROMPT, CMD_PROMPT_CLR) << std::endl;
	printLineBreaks(1, LINE_BREAK_COLOR);
}

int	main(void) {

	PhoneBook 	phonebook;
	std::string	command;

	// print out phonebook usage instructions
	printInstructions();

	while (true) {

		// print prompt and take input
		std::cout << std::left << std::setw(25) << printColorNoReset(PROMPT_TEXT, PROMPT_CLR);
		std::getline(std::cin, command);
		std::cout << RESET;

		if (TRIM_INPUTS)
			command = trim(command);

		// handle commands
		if (command == CMD1)
			phonebook.add();
		else if (command == CMD2)
			phonebook.search();
		else if (command == CMD4)
		{
			if (phonebook.exit())
			{
				std::cout << printColor(EXIT_TEXT, EXIT_TEXT_CLR) << std::endl;
				break ;
			}
		}
		else if (std::cin.eof())
		{
			std::cout << EOF_DETECTED_TEXT << std::endl;
			return (0);
		}
		// else
		// 	;
		//{
		//	std::cout << printColor(BAD_PROMPT_TEXT, BAD_PROMPT_CLR) << std::endl;
		//	std::cout << std::endl;
		//}
	}
	return 0;
}
