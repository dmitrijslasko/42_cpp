#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "utils.hpp"

int	main ( void ) {

	Animal* a1 = new Dog(); // ✅ via pointer or reference to base
	//a1 = dynamic_cast<Cat>(a1);
	//a1 = new Cat();
	std::cout << a1->getType() << std::endl;
	return 0;
}
