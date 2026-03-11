#include <iostream>
#include <iomanip>

#include "ScalarConverter.hpp"
#include "utils.hpp"


const char* TRUE  = "✅ true";
const char* FALSE = "❌ false";


int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}


	std::string literal(argv[1]);

	printSeparator();
	std::cout << std::left << std::setw(ScalarConverter::WIDTH);
	std::cout << "INPUT: " << literal << std::endl;
	printSeparator();
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "Is char: " << (ScalarConverter::isChar(literal) ? TRUE : FALSE) << std::endl;
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "Is int: " << (ScalarConverter::isInt(literal) ? TRUE : FALSE) << std::endl;
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "Is float: " << (ScalarConverter::isFloat(literal) ? TRUE : FALSE) << std::endl;
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "Is double: " << (ScalarConverter::isDouble(literal) ? TRUE : FALSE) << std::endl;
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "Is pseudo-float: " << (ScalarConverter::isPseudoFloat(literal) ? TRUE : FALSE) << std::endl;
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "Is pseudo-double: " << (ScalarConverter::isPseudoDouble(literal) ? TRUE : FALSE) << std::endl;
	printSeparator();

	// std::cout << "CONVERSIONS: " << std::endl;
	// printSeparator();
	ScalarConverter::convert(literal);
	printSeparator();

	return 0;
}
