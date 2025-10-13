#include <iostream>
#include <string>   // for std::string
#include <cctype>   // for std::toupper

#define PLACEHOLDER_TEXT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << PLACEHOLDER_TEXT << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		std::string s = std::string(argv[i]);
		// same as std::string s(argv[i]);
		for (std::size_t j = 0; j < s.size(); ++j) {
			// toupper() function signature: int std::toupper(int ch);
			s[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
		}
		std::cout << s;
	}
	std::cout << std::endl;
	return 0;
}
