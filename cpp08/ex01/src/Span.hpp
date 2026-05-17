#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _numbers;
		
		Span();						// default constructor is private to prevent instantiation without specifying N

	public:
		Span(unsigned int N);		// parameterized constructor
		~Span();					// destructor
		Span(const Span &other);	// copy constructor
		Span &operator=(const Span &other);	// copy assignment operator
		
		// Member functions aka public methods
		void addNumber(int number);

		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			// Check if the range will exceed our maximum capacity
			if (_numbers.size() + std::distance(begin, end) > _N) {
				throw ContainerFullException();
			}
			// Insert the entire range at once
			_numbers.insert(_numbers.end(), begin, end);
		}

		unsigned int shortestSpan();
		unsigned int longestSpan();

		void printNumbers() const; // Utility function to print all numbers (for debugging/testing)

		// Nested custom exception classes for descriptive errors
		class ContainerFullException : public std::exception {
			virtual const char* what() const throw() { return "Span is already full!"; }
		};

		class NoSpanException : public std::exception {
			virtual const char* what() const throw() { return "Not enough elements to calculate a span!"; }
		};
};

#endif

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
