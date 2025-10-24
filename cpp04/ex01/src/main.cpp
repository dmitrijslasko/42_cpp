#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "utils.hpp"

#define ARRAY_SIZE 10

int	main ( void ) {
	//Animal* animals[ARRAY_SIZE];

	//std::cout << "\nCREATING DOGS AND CATS" << std::endl;
	//printSeparator();
	//for (int i = 0; i < ARRAY_SIZE / 2; i++)
	//	animals[i] = new Dog();
	//for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
	//	animals[i] = new Cat();

	//std::cout << "\nMAKING SOUNDS" << std::endl;
	//printSeparator();
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	animals[i]->makeSound();
	//}

	//std::cout << "\nDELETION" << std::endl;
	//printSeparator();
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	std::cout << i << " -------------------------------------" << std::endl;
	//	delete animals[i];
	//}

	Dog dog1;
	dog1.addNewIdea("I am a dog");

	std::cout << "Creating a new dog instance using a copy constructor\n";
	Dog dog2 = Dog(dog1);

	std::cout << "Overwrting the new dog's idea\n";
	dog2.addNewIdea("I am a cat");

	dog1.printAllIdeas();
	dog2.printAllIdeas();

	return 0;
}
