#include <iostream>
#include "iter.hpp"
#include "utils.hpp"

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}

template <typename T>
void addOne(T &x) {
    x += 1;
}

void hideValue(const int &x) {
	(void) x;
	std::cout << "* ";
}
 
int main() {
	{
		printSeparator();
		int arr[] = {1, 2, 3, 4, 5};
		std::cout << "Original array:" << std::endl;
		iter(arr, 5, print);
		std::cout << std::endl;
		printSeparator();
		iter(arr, 5, addOne);
		std::cout << "Array after adding 1 to each element:" << std::endl;
		iter(arr, 5, print);
		std::cout << std::endl;
		printSeparator();
	}
	{
		printSeparator();
		char arr[] = {'a', 'b', 'c', 'd', 'e'};
		std::cout << "Original array:" << std::endl;
		iter(arr, 5, print);
		std::cout << std::endl;
		printSeparator();
		iter(arr, 5, addOne);
		std::cout << "Array after adding 1 to each element:" << std::endl;
		iter(arr, 5, print);
		std::cout << std::endl;
		printSeparator();
	}
	{
		printSeparator();
		int arr[] = {1, 2, 3, 4, 5};
		iter(arr, 5, hideValue);
		std::cout << std::endl;
		printSeparator();
	}

	return 0;
}
