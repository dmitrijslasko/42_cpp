#ifndef DOG_H
# define DOG_H

# include <string>
# include <iostream>

# include "Animal.hpp"

class Dog : public Animal {

	private:
	
	public:
		// Constructor (default)
		Dog();

		// Constructor (parameterized)
		Dog(std::string type);

		// Copy constructor
		Dog(const Dog &other);

		// Copy assignment operator
		Dog &operator=(const Dog &other);

		// Destructor
		~Dog();

		// Public methods
		void makeSound( void );
};

#endif
