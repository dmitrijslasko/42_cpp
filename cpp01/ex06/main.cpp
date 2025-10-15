#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

	if (argc < 2) {
		std::cout << "It's more fun with at least 1 argument!" << std::endl;
		return 0;
	}

	Harl harl;
	harl.complain(argv[1]);

	return 0;
}
