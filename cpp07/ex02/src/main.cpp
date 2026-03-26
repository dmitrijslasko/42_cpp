#include <iostream>

#include "Array.hpp"

int main()
{
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i * 10;

	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	try
	{
		std::cout << arr[10] << std::endl; // This should throw an exception
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
