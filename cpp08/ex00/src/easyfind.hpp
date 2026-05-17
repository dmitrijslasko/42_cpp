#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
# include<exception>

class CustomException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
	
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
        throw CustomException();
    }

	return it;
}

#endif

// Write a function template easyfind that accepts a type T. 
// It takes two parameters: the first one is of type T, and the second one is an integer.

// Assuming T is a container of integers, this function has to find the first occurrence
// of the second parameter in the first parameter.

// If no occurrence is found, you can either throw an exception or return an error value
// of your choice. If you need some inspiration, analyze how standard containers behave.

// Of course, implement and turn in your own tests to ensure everything works as expected.


// Examples of possible containers:
// std::vector<int>
// std::list<int>
// std::deque<int>


// 2. What should the function return?
// Standard containers usually use iterators for searching.
// For example, std::find returns:
// iterator to found element
// or:
// container.end()
// if nothing was found.
// So the most natural solution is:
// return an iterator

// Standard containers are the built-in container types provided by the C++ Standard Library.
// They store collections of values, such as numbers, strings, objects, etc.


// Common standard containers

// Sequence containers
// std::vector<int> v; // dynamic array
// std::list<int> l;   // linked list
// std::deque<int> d;  // double-ended queue
// For your easyfind exercise, these are the most relevant ones.

// Associative containers
// These store elements in sorted/searchable structures.
// std::set<int>
// std::map<std::string, int>
// std::multiset<int>
// std::multimap<std::string, int>

// Unordered containers
// These use hash tables.
// std::unordered_set<int>
// std::unordered_map<std::string, int>
// They are usually faster for lookup, but do not keep elements sorted.
