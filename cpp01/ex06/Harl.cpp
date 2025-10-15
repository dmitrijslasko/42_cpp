# include <string>
# include <iostream>
# include "Harl.hpp"

# define SHOW_DEBUG_OUTPUT 0

// 1. Constructor
Harl::Harl( void ) {
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "> Harl.class default constructor called" << std::endl;
}

// 2. Destructor
Harl::~Harl( void ) {
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "> Harl.class destructor called" << std::endl;
}

void Harl::debug( void ) {
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "Harl.class debug() function" << std::endl;
	std::cout << B_GREEN << "I would like to DEBUG!" << DEFAULT << std::endl;
}

void Harl::info( void ) {
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "Harl.class info() function" << std::endl;
	std::cout << B_YELLOW << "I need more INFO on this!" << DEFAULT << std::endl;
}

void Harl::warning( void ) {
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "Harl.class warning() function" << std::endl;
	std::cout << B_ORANGE << "I throw my WARNING!" << DEFAULT << std::endl;
}

void Harl::error( void ) {
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "Harl.class error() function" << std::endl;
	std::cout << B_RED << "It was my ERROR to even come here!" << DEFAULT << std::endl;
}

void Harl::complain( std::string level ) {

	// dispatch table
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int complaintLevel = -1;
	if (SHOW_DEBUG_OUTPUT)
		std::cout << "Harl complains" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i]) {
			complaintLevel = i;
			break;
		}
	}

	switch(complaintLevel){
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
