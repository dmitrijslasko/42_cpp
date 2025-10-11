#include <iostream>
#include <fstream>

// #include "Animal.hpp"

int	main(void) {

	std::ifstream	ifs("input");
	std::ofstream	ofs("output");
	std::string	in;

	ifs >> in;
	ofs << in;

	return 0;
}