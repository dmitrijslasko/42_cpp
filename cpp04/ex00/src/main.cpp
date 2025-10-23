#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "utils.hpp"

int	main ( void ) {
	{
		printSeparator();
		std::cout << B_GREEN << "✅ CORRECT BEHAVIOUR WITH VIRTUAL KEYWORD\n" << RESET;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		meta->makeSound();
		//return 0;
	}
	{
		printSeparator();
		std::cout << B_RED << "❌ INCORRECT BEHAVIOUR WITHOUT VIRTUAL KEYWORD\n" << RESET;
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		meta->makeSound();
		//return 0;
	}
	{
		printSeparator();
		Animal animal;
		animal.makeSound();
		std::cout << "Instance type: " << animal.getType() << std::endl;
	}
	{
		printSeparator();
		Dog dog;
		dog.makeSound();
		std::cout << "Instance type: " << dog.getType() << std::endl;
	}
	{
		printSeparator();
		Cat cat;
		cat.makeSound();
		std::cout << "Instance type: " << cat.getType() << std::endl;
	}
	printSeparator();
	return 0;
}
