#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <string>
# include "Weapon.hpp"

class HumanA {
	public:
		// 1. Constructors
		// HumanA();                   		            // default constructor
		HumanA( std::string name, Weapon& weapon );		// parameterized constructor

		// 2. Destructor
		~HumanA();

		// 3. Public member functions
		void attack( void );
		
	private:
		std::string _name;
		Weapon& _weapon;
};

#endif
