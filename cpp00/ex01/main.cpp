#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

#include "Contact.hpp"
#include "PhoneBook.hpp"

#include "settings.h"
#include "utilities.h"

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
			command = trimString(command);

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
	}
	return 0;
}
