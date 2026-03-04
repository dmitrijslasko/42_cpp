#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}

	std::string literal(argv[1]);
	std::cout << "Input: " << literal << std::endl;
	std::cout << "Is char: " << (ScalarConverter::isChar(literal) ? "true" : "false") << std::endl;
	std::cout << "Is int: " << (ScalarConverter::isInt(literal) ? "true" : "false") << std::endl;
	std::cout << "Is float: " << (ScalarConverter::isFloat(literal) ? "true" : "false") << std::endl;

	return 0;
}
