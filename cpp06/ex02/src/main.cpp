#include <cstdlib>
#include <ctime>
#include <iostream>

#include "identify.hpp"
#include "utils.hpp"

int main()
{
    printSeparator();
	std::srand(std::time(NULL));

	Base* base = generate();
    identify(base);
    identify(*base);
    printSeparator();
    
	// Clean up
	delete base;

	return 0;
}
