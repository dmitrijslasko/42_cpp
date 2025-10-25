#include <string>
#include <iostream>

void	printSeparator( void ) {
	std::string out = "";
	for (int i = 0; i < 60; i++)
		out += '=';
	std::cout << out << std::endl;
}
