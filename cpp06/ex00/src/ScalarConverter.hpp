#include <string>

class ScalarConverter {
	private:
		// constructor
		ScalarConverter();
		// destructor
		~ScalarConverter();
		// copy constructor
		ScalarConverter(const ScalarConverter &other);
		// assignment operator
		ScalarConverter &operator=(const ScalarConverter &other);

		static bool isPseudoLiteral(const std::string &s);

		public:

		static bool isChar(const std::string &s);
		static bool isInt(const std::string &s);
		static bool isFloat(const std::string &s);
		static bool isDouble(const std::string &s);

		static void convert(std::string &literal);
};

