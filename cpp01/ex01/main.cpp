#include <cstdlib>
#include "Zombie.hpp"
#include <sstream>

// is it possible to create a horde on stack?
//Technically — yes, but only if you know the size at compile time.

int main( int argc, char *argv[] ) {

	// check argument count
	if (argc < 3 || argc > 3) {
		std::cout << "I strictly insist that you provide 2 arguments:\n(1) zombie count and\n(2) zombie name" << std::endl;
		return 1;
	}

	// This is C style
	//int N = std::atoi(argv[1]);
	int N;
	std::istringstream(argv[1]) >> N;

	if (N < 0) {
		std::cout << "Zombie count can't be less than 0." << std::endl;
		return 1;
	}

	// creating zombie horde
	Zombie *horde = zombieHorde(N, argv[2]);
	if (!horde)
	{
		std::cout << "No horde got created!" << std::endl;
		return 1;
	}

	for (int i = 0; i < N; i++) {
		std::cout << "Checking horde member " << i << ":" << std::endl;
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
