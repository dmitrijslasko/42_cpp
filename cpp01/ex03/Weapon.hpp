#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon {
	public:
		// 1. Constructors
		Weapon();                   	// default constructor
		Weapon( std::string type );		// parameterized constructor

		// 2. Destructor
		~Weapon();

		// 3. Public member functions
		// void announce( void );
		std::string& getType( void );
		void setType( std::string type );
		
	private:
		std::string _type;
};

#endif
