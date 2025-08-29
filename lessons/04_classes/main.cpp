#include "Sample.class.hpp"
#include <iostream>

void	f0(void)
{
	Sample human1;
	std::cout << "Population size 2: " << Sample::getPopulationSize() << std::endl;
}

void	f1(void)
{
	std::cout << "Population size 1: " << Sample::getPopulationSize() << std::endl;
	f0();
	std::cout << "Population size 3: " << Sample::getPopulationSize() << std::endl;
}

int	main(void) {
	f1();
	return 0;
}