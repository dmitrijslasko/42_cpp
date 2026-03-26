#include <iostream>
#include "whatever.hpp"
#include "utils.hpp"

int main() {

	// Swap test
	{
		std::cout << "SWAP TEST:" << std::endl;
		int a = 2;
		int b = 5;
		printSeparator();
		std::cout << "Before swap: " << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		printSeparator();
		std::cout << "After swap: " << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		printSeparator();
		std::cout << std::endl;
	}
	
	// Min and Max test
	{
		std::cout << "MIN AND MAX TEST:" << std::endl;
		printSeparator();
		int a = 2;
		int b = 5;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		printSeparator();
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
		printSeparator();
	}

	// Original subject test
	{
		int a = 2;
		int b = 3;
		swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return 0;
}
