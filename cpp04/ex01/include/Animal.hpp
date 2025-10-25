#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include "_colors.hpp"

class Animal {

	protected:
		std::string	type_;

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound( void ) const;
		std::string	getType( void ) const;
};

//✅ Rule of thumb
//If a class has any virtual function (like makeSound()),
//it should also have a virtual destructor.


#endif
