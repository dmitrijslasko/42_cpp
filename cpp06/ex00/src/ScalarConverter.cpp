#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

#include "ScalarConverter.hpp"

// Type detection functions
// Type detection = syntax + range validity

bool ScalarConverter::isPseudoFloat(const std::string& s)
{
	return (s == "nanf" || s == "+inff" || s == "-inff");
}

bool ScalarConverter::isPseudoDouble(const std::string& s)
{
	return (s == "nan" || s == "+inf" || s == "-inf");
}

bool ScalarConverter::isChar(const std::string &s) {
	if (s.length() != 1)
		return false;
	if (!isdigit(s[0]))
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string &s) {

	if (s.empty())
    	return false;

	if (isdigit(s[0]) || (s[0] == '-' && s.length() > 1 && isdigit(s[1])))
		return false;
	
	return true;

	// long value = std::strtol(s.c_str(), NULL, 10);
	
	// if (value < std::numeric_limits<int>::min() ||
	// 	value > std::numeric_limits<int>::max() ||
	// 	std::isnan(value) || std::isinf(value))
	// 	return false;

	// size_t i = 0;
	// if (s[i] == '-')
	// 	i++;

	// if (i == s.length())
	// 	return false;

	// while (i < s.length()) {
	// 	if (!isdigit(s[i]))
	// 		return false;
	// 	i++;
	// }
	// return true;
}

bool ScalarConverter::isFloat(const std::string &s) {

	bool hasDot = false;

	if (s[s.length() - 1] != 'f')
		return false;

	size_t i = 0;

	if (s[i] == '-')
		i++;
	while (i < s.length() - 1) {
		if (s[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!isdigit(s[i]))
			return false;
		i++;
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string &s) {

	bool hasDot = false;

	size_t i = 0;

	if (s[i] == '-')
		i++;
	while (i < s.length()) {
		if (s[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!isdigit(s[i]))
			return false;
		i++;
	}
	return hasDot;
}


// Printing functions
static void printChar(double value) {

	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "char: ";

	if (value < std::numeric_limits<char>::min() ||
		value > std::numeric_limits<char>::max() ||
		std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	else if (value < 32 || value == 127)
	{
		std::cout << "non displayable" << std::endl;
		return;
	}
	std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
}

static void printInt(double value) {
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "int: ";

	if (value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max() ||
		std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "float: ";

	if (std::isnan(value) || std::isinf(value)) {
		std::cout << static_cast<float>(value) << "f" << std::endl;
		return;
	}

	if (value == static_cast<int>(value))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(6);

	std::cout << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value) {
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "double: ";

	// std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<double>(value);
	std::cout << std::endl;
}


void ScalarConverter::convert(const std::string &literal) {

    double value;

    if (isChar(literal)) {
        value = static_cast<double>(literal[0]);
    } else {
        char* end;
        value = strtod(literal.c_str(), &end);

        if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
            std::cout << "Invalid input" << std::endl;
            return;
        }
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}