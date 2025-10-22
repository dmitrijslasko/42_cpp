#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;

void	printSeparator( void ) {
	cout << "---------------------------------------------------------\n";
}

int	main ( void ) {
	{
		printSeparator();
		cout << "DEFAULT CONSTRUCTOR\n";
		ClapTrap	unnamed = ClapTrap();
	}
	{
		printSeparator();
		cout << "PARAMETERIZED CONSTRUCTOR\n";
		ClapTrap	johnhy("Johnny");

		for (int i = 0; i < 15; i++)
			johnhy.attack("Jimmy");
		johnhy.beRepaired(2);
		johnhy.takeDamage(1);
		johnhy.takeDamage(15);
		johnhy.takeDamage(15);
		johnhy.takeDamage(15);
		johnhy.takeDamage(15);
		johnhy.beRepaired(15);
	}
	{
		printSeparator();
		cout << "COPY CONSTRUCTOR\n";
		ClapTrap	johnhy("Johny");
		ClapTrap	jimmy(johnhy);
	}
	{
		printSeparator();
		cout << "COPY ASSIGNMENT OPERATOR\n";
		ClapTrap	johnhy("Johny");
		ClapTrap	jimmy;
		jimmy = johnhy;
	}
	{
		printSeparator();
		cout << "CHILD CLASS METHODS\n";
		ScavTrap	scavJohnhy("ScavJohny");
		scavJohnhy.attack("Molly");
		scavJohnhy.takeDamage(30);
	}
	printSeparator();
	return 0;
}
