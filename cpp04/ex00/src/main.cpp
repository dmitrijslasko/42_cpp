#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using std::cout;
using std::endl;

void	printSeparator( void ) {
	cout << "---------------------------------------------------------\n";
}

int	main ( void ) {
	{
		Animal animal("elephant");
		animal.makeSound();
	}
	{
		printSeparator();
		Dog dog("Doggie");
		dog.makeSound();
		cout << dog.getType() << endl;
	}
	{
		printSeparator();
		Cat cat("Cattie");
		cat.makeSound();
		cout << cat.getType() << endl;
	}
	printSeparator();
	return 0;
}
