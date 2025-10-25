#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "colors.hpp"
#include "utils.hpp"

#define ARRAY_SIZE 10

int	main ( void ) {

	printSeparator();
	std::cout << "TEST 1 - CHECKING IF NEW BRAIN IS A DEEP COPY\n";
	Dog basic;
	{
		Dog tmp = basic;
	}
	{
		printSeparator();
		std::cout << "TEST 2\n";
		Dog dog1;
		dog1.addNewIdea(std::string(YELLOW) + "I am a dog" + RESET);

		std::cout << "Creating a new dog instance using a copy constructor\n";
		Dog dog2 = Dog(dog1);

		std::cout << "Adding more of the new dog's ideas\n";
		dog2.addNewIdea(std::string(MAGENTA) + "I am a new dog" + RESET);
		dog2.addNewIdea(std::string(MAGENTA) + "I am a good dog" + RESET);
		dog2.addNewIdea(std::string(MAGENTA) + "I am better than the first dog" + RESET);

		dog1.printAllIdeas();
		dog2.printAllIdeas();
	}
	{
		//Animal *animals[10];
		//for (int i = 0; i < 5; i++)
		//	animals[i] = new Dog();
		//for (int i = 5; i < 10; i++)
		//	animals[i] = new Cat();
		//for (int i = 0; i < 10; i++)
		//	delete animals[i];
	}

	return 0;
}

//
