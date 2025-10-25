#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>
# include "_colors.hpp"

class WrongAnimal {

	protected:
		std::string	type_;

	public:
		WrongAnimal();
		//WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();

		void makeSound( void ) const;
		std::string	getType( void ) const;
};

#endif
