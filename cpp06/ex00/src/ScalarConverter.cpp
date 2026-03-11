#include <iostream>
#include <iomanip>

#include "ScalarConverter.hpp"

bool ScalarConverter::isPseudoFloat(const std::string& s)
{
    return (s == "nanf" || s == "+inff" || s == "-inff");
}

bool ScalarConverter::isPseudoDouble(const std::string& s)
{
    return (s == "nan" || s == "+inf" || s == "-inf");
}

bool ScalarConverter::isChar(const std::string &s) {
    return (s.length() == 1 && !isdigit(s[0]));
}

bool ScalarConverter::isInt(const std::string &s) {
	size_t i = 0;
	if (s[i] == '-')
		i++;

	if (i == s.length())
		return false;

	while (i < s.length()) {
		if (!isdigit(s[i]))
			return false;
		i++;
	}
	return true;
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

void ScalarConverter::convert(const std::string &literal) {

	// value will store the numeric representation of the input
	double 	value;

	value = static_cast<double>(literal[0]);

	/* char */
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "char: ";
	std::cout << static_cast<char>(literal[0]);
	std::cout << std::endl;

	/* int */
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "int: ";
	std::cout << static_cast<int>(literal[0]);
	std::cout << std::endl;

	/* float */
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(literal[0]) << "f";
	std::cout << std::endl;

	/* double */
	std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "double: ";
	std::cout << static_cast<double>(literal[0]);
	std::cout << std::endl;
}
