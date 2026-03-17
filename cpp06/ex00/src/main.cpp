#include <iostream>
#include <iomanip>

#include "ScalarConverter.hpp"
#include "utils.hpp"

// global constants for output formatting
// better thant macros because they are typed and scoped, and they can be used in expressions without side effects
const char* TRUE  = "✅ true";
const char* FALSE = "❌ false";

void printCheck(const std::string& label, bool value) {
    std::cout << std::left << std::setw(ScalarConverter::WIDTH)
              << label
              << (value ? TRUE : FALSE)
              << std::endl;
}

int main(int argc, char **argv) {

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}

	std::string literal(argv[1]);

	printSeparator();
	std::cout << std::left << std::setw(ScalarConverter::WIDTH);
	std::cout << "Input: " << literal << std::endl;
	printSeparator();

	// type checks
	printCheck("Is char: ", ScalarConverter::isChar(literal));
	printCheck("Is int: ", ScalarConverter::isInt(literal));
	printCheck("Is float: ", ScalarConverter::isFloat(literal));
	printCheck("Is double: ", ScalarConverter::isDouble(literal));
	printCheck("Is pseudo-float: ", ScalarConverter::isPseudoFloat(literal));
	printCheck("Is pseudo-double: ", ScalarConverter::isPseudoDouble(literal));
	
	printSeparator();

	if (!ScalarConverter::isChar(literal) && 
		!ScalarConverter::isInt(literal) && 
		!ScalarConverter::isFloat(literal) && 
		!ScalarConverter::isDouble(literal) &&
	    !ScalarConverter::isPseudoFloat(literal) && 
		!ScalarConverter::isPseudoDouble(literal))
	{
		std::cerr << "Invalid literal" << std::endl;
		printSeparator();
		return 1;
	}

	// conversion and printing
	ScalarConverter::convert(literal);
	printSeparator();

	return 0;
}
