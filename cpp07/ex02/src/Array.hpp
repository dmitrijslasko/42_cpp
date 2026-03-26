#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    // Constructors
    Array();
    Array(unsigned int n);
    Array(const Array& other);

    // Destructor
    ~Array();

    // Assignment operator
    Array& operator=(const Array& other);

    // Access operator
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // Size
    unsigned int size() const;

	// Exceptions
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif