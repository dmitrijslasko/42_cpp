#ifndef CAT_H
# define CAT_H

# include <string>
# include <iostream>

# include "Animal.hpp"

class Cat : public Animal {

	private:
	
	public:
		// Constructor (default)
		Cat();

		// Constructor (parameterized)
		Cat(std::string type);

		// Copy constructor
		Cat(const Cat &other);

		// Copy assignment operator
		Cat &operator=(const Cat &other);

		// Destructor
		~Cat();

		// Public methods
		void makeSound( void );
};

#endif
