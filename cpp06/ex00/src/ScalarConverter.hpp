#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

	private:
		// constructor
		ScalarConverter();
		// copy constructor
		ScalarConverter(const ScalarConverter &other);
		// assignment operator
		ScalarConverter &operator=(const ScalarConverter &other);
		// destructor
		~ScalarConverter();

	public:

		static const int WIDTH = 20;

		static bool isChar(const std::string &s);
		static bool isInt(const std::string &s);
		static bool isFloat(const std::string &s);
		static bool isDouble(const std::string &s);

		static bool isPseudoFloat(const std::string& s);
		static bool isPseudoDouble(const std::string& s);

		static void convert(const std::string &literal);
};

#endif
