#include <iostream>
#include <list>

#include "Span.hpp"

int main() {
	std::cout << "---------------------" << std::endl;
	{
		unsigned int N = 10;
			// 1. Seed the random number generator so numbers change every run
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		// 2. Create a temporary vector to hold our 10,000 numbers
		std::vector<int> my_numbers;
		my_numbers.reserve(N); // Reserve memory for performance

		// 3. Fill the temporary vector with 10,000 random values
		for (unsigned int i = 0; i < N; ++i) {
			my_numbers.push_back(std::rand());
		}

		try {
				// 4. Create your Span class with room for 10,000 items
				Span sp(N);

				// 5. Add all 10,000 numbers in ONE single line using your template!
				sp.addNumbers(my_numbers.begin(), my_numbers.end());

				sp.printNumbers();
				// 6. Calculate and print the results
				std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
				std::cout << "Longest Span: "  << sp.longestSpan() << std::endl;

			} catch (const std::exception &e) {
				std::cerr << "An error occurred: " << e.what() << std::endl;
			}
	}
	return 0;
}
