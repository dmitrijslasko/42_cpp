#include <string>

class ScalarConverter {
	private:
		ScalarConverter();		// constructor
		~ScalarConverter();		// destructor
		ScalarConverter(const ScalarConverter &other);				// copy constructor
		ScalarConverter &operator=(const ScalarConverter &other);	// assignment operator

	public:
		static void convert(std::string &literal);
}
