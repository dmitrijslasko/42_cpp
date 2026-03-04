#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &s) {
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
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
