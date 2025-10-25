#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		//Animal test;
	}
	{
		Animal* a1 = new Dog();
		std::cout << a1->getType() << std::endl;
	}
	return 0;
}
