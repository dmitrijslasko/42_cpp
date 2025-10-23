#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>
# include "colors.hpp"

class Animal {

	protected:
		std::string	_type;

	public:
		// Constructor (default)
		Animal();

		// Constructor (parameterized)
		Animal(std::string type);

		// Copy constructor
		Animal(const Animal &other);

		// Copy assignment operator
		Animal &operator=(const Animal &other);

		// Destructor
		virtual ~Animal();

		// Public methods
		virtual void makeSound( void ) const;
		std::string	getType( void ) const;
};

#endif
