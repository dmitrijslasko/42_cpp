#include <iostream>
#include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "The memory address of the string variable:" << std::endl;
	std::cout << &string << std::endl << std::endl;

	std::cout << "The memory address held by stringPTR:" << std::endl;
	std::cout << stringPTR << std::endl << std::endl;

	std::cout << "The memory address held by stringREF:" << std::endl;
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable:" << std::endl;
	std::cout << string << std::endl << std::endl;

	std::cout << "The value pointed to by stringPTR:" << std::endl;
	std::cout << *stringPTR << std::endl << std::endl;

	std::cout << "The value pointed to by stringREF:" << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}
