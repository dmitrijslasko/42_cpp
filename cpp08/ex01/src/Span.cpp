#include <iostream>
#include <algorithm>
#include <exception>

#include "Span.hpp"

Span::Span(unsigned int n) : _N(n) {
    // Vector reserves memory up front for efficiency
    _numbers.reserve(n);
	std::cout << "Span created with capacity: " << n << std::endl;
}

Span::Span(const Span &src) 
    : _N(src._N), _numbers(src._numbers) 
{
    // The body can remain completely empty because the initializer 
    // list directly triggers the deep copy constructor of std::vector
}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        this->_N = rhs._N;
        this->_numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N) {
        throw ContainerFullException();
    }
    _numbers.push_back(number);
	std::cout << "Added number: " << number << std::endl;
}

unsigned int Span::longestSpan() {

    if (_numbers.size() <= 1) {
        throw NoSpanException();
    }

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(maxVal - minVal);
    // Distance is the absolute difference between max and min
    // return static_cast<unsigned int>(std::abs(maxVal - minVal));
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() <= 1) {
        throw NoSpanException();
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();

    for (size_t i = 0; i <sortedNumbers.size() - 1; ++i) {
        unsigned int span = static_cast<unsigned int>(sortedNumbers[i + 1] - sortedNumbers[i]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

void Span::printNumbers() const {
    std::cout << "Numbers in Span: " << std::endl;
    for (size_t i = 0; i < _numbers.size(); ++i) {
        std::cout << _numbers[i];
        if (i < _numbers.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Develop a Span class that can store a maximum of N integers. N is an unsigned int
// variable and will be the only parameter passed to the constructor.

// This class will have a member function called addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.

// Next, implement two member functions: shortestSpan() and longestSpan()

// They will respectively find out the shortest span or the longest span (or distance, if
// you prefer) between all the numbers stored, and return it. If there are no numbers stored,
// or only one, no span can be found. Thus, throw an exception.

// Of course, you will write your own tests, and they will be far more thorough than the
// ones below. Test your Span with at least 10,000 numbers. More would be even better.
