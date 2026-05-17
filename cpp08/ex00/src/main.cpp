#include <iostream>
#include "easyfind.hpp"

#include <list>

template <typename T>
void testEasyFind(T &container, int value)
{
	
	try {
		typename T::iterator it = easyfind(container, value);
		if (it != container.end())
		std::cout << "found: " << *it << std::endl;
	} catch (const CustomException &e) {
			std::cout << e.what() << std::endl;
	}
}

int main() {
	std::cout << "---------------------" << std::endl;
	{
		std::cout << "Vector tests:" << std::endl;
		// Vector is a dynamic array that can resize itself automatically when elements are added or removed.
		// It only allows for efficient insertion and deletion of elements at the end of the vector, but it provides fast access to elements by index.
		std::vector<int> integers_vector;
		integers_vector.push_back(1);
		integers_vector.push_back(2);

		testEasyFind(integers_vector, 2);
		testEasyFind(integers_vector, 42);
		std::cout << "---------------------" << std::endl;
	}
	{
		std::cout << "List tests:" << std::endl;
		// List is a doubly linked list that allows for efficient insertion and deletion of elements at any position in the list.
		// It allows for fast insertion and deletion of elements at any position in the list, but it does not provide fast access to elements by index.

		std::list<int> integers_list;
		integers_list.push_back(1);
		integers_list.push_back(2);
		integers_list.push_front(3);

		testEasyFind(integers_list, 2);
		testEasyFind(integers_list, 42);
		std::cout << "---------------------" << std::endl;
	}
	{
		std::cout << "Deque tests:" << std::endl;
		// Deque is a double-ended queue that allows for efficient insertion and deletion of elements at both the front and back of the deque.
		// It allows for fast insertion and deletion of elements at both the front and back of the deque, but it does not provide fast access to elements by index.

		std::deque<int> integers_deque;
		integers_deque.push_back(1);
		integers_deque.push_back(2);
		integers_deque.push_front(3);
		testEasyFind(integers_deque, 2);
		testEasyFind(integers_deque, 3);
		std::cout << "---------------------" << std::endl;
	}
	return 0;
}
