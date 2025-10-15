#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		// 1. Constructors
		HumanB( std::string name );                   	// parameterized constructor 1
		HumanB( std::string name, Weapon *weapon );		// parameterized constructor 2

		// 2. Destructor
		~HumanB();

		// 3. Public member functions
		void attack( void );
		void setWeapon( Weapon &weapon );

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif
