	#include <iostream>
	#include <iomanip>
	#include <cstdlib>
	#include <cerrno>
	#include <limits>
	#include <cmath>
	#include <cctype>

	#include "ScalarConverter.hpp"

	// Type detection functions
	// Type detection = syntax + range validity

	bool ScalarConverter::isPseudoFloat(const std::string& s)
	{
		return (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff");
	}

	bool ScalarConverter::isPseudoDouble(const std::string& s)
	{
		return (s == "nan" || s == "+inf" || s == "-inf" || s == "inf");
	}

	bool ScalarConverter::isChar(const std::string &s) {
		return (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]));
	}

	bool ScalarConverter::isInt(const std::string &s) {
		if (s.empty())
			return false;

		char *end;
		errno = 0;
		
		// on error, strtol returns LONG_MAX or LONG_MIN and sets errno to ERANGE
		long value = std::strtol(s.c_str(), &end, 10);

		// check conversion validity
		if (*end != '\0')
			return false;

		// check overflow / underflow
		if (errno == ERANGE ||
			value < std::numeric_limits<int>::min() ||
			value > std::numeric_limits<int>::max())
			return false;

		return true;
	}

	bool ScalarConverter::isFloat(const std::string &s) {

		if (s.empty())
			return false;

		if (s[s.length() - 1] != 'f')
			return false;

		size_t i = 0;
		bool hasDot = false;
		bool hasDigit = false;

		// sign
		if (s[i] == '+' || s[i] == '-')
			i++;

		if (i >= s.length() - 1) // nothing before 'f'
			return false;

		while (i < s.length() - 1) {
			if (s[i] == '.') {
				if (hasDot)
					return false;
				hasDot = true;
			}
			else if (std::isdigit(s[i])) {
				hasDigit = true;
			}
			else {
				return false;
			}
			i++;
		}

		return hasDot && hasDigit;
	}

	bool ScalarConverter::isDouble(const std::string &s) {

		if (s.empty())
			return false;

		size_t i = 0;
		bool hasDot = false;
		bool hasDigit = false;

		// sign
		if (s[i] == '+' || s[i] == '-')
			i++;

		if (i == s.length())
			return false;

		while (i < s.length()) {
			if (s[i] == '.') {
				if (hasDot)
					return false;
				hasDot = true;
			}
			else if (std::isdigit(s[i])) {
				hasDigit = true;
			}
			else {
				return false;
			}
			i++;
		}

		return hasDigit;
	}

	static int getPrecision(const std::string& s) {
		size_t dot = s.find('.');
		if (dot == std::string::npos)
			return 1;

		size_t end = s.find_first_not_of("0123456789", dot + 1);
		int precision = (end == std::string::npos ? s.length() : end) - dot - 1;

		if (precision == 0)
			return 1;

		return precision;
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
			std::cout << "Non displayable" << std::endl;
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

static void printFloat(double value, const std::string& literal) {
    std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "float: ";

    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (std::isinf(value)) {
        if (value < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
        return;
    }

    int precision = getPrecision(literal);
    std::cout << std::fixed << std::setprecision(precision);

    float f = static_cast<float>(value);

    if (std::isinf(f)) {
        if (f < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
        return;
    }

    std::cout << f << "f" << std::endl;
}

	static void printDouble(double value, const std::string& literal) {
		std::cout << std::left << std::setw(ScalarConverter::WIDTH) << "double: ";

		if (std::isnan(value)) {
			std::cout << "nan" << std::endl;
			return;
		}
		if (std::isinf(value)) {
			if (value < 0)
				std::cout << "-inf" << std::endl;
			else
				std::cout << "+inf" << std::endl;
			return;
		}

		int precision = getPrecision(literal);
		std::cout << std::fixed << std::setprecision(precision);

		std::cout << value << std::endl;
	}


	void ScalarConverter::convert(const std::string &literal) {

		double value;

		if (isChar(literal)) {
			value = static_cast<double>(literal[0]);
		} else {
			char* end;
			value = strtod(literal.c_str(), &end);
		}

		printChar(value);
		printInt(value);
		printFloat(value, literal);
		printDouble(value, literal);
	}
