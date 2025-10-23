#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define PARENT_CLR 	B_BLUE
#define CHILD_CLR 	B_CYAN

using std::cout;

void	printSeparator( void ) {
	cout << "---------------------------------------------------------\n";
}

int	main ( void ) {
	{
		printSeparator();
		cout << PARENT_CLR << "PARENT - DEFAULT CONSTRUCTOR\n" << RESET;
		ClapTrap	unnamed = ClapTrap();
	}
	{
		printSeparator();
		cout << CHILD_CLR << "CHILD - DEFAULT CONSTRUCTOR\n" << RESET;
		ScavTrap	unnamed = ScavTrap();
	}
	{
		printSeparator();
		cout << PARENT_CLR << "PARENT - PARAMETERIZED CONSTRUCTOR\n" << RESET;
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
		cout << CHILD_CLR << "CHILD - PARAMETERIZED CONSTRUCTOR\n" << RESET;
		ScavTrap	johnhy("ScavJohnny");

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
		cout << PARENT_CLR << "PARENT - COPY CONSTRUCTOR\n" << RESET;
		ClapTrap	johnhy("Johny");
		ClapTrap	jimmy(johnhy);
	}
	{
		printSeparator();
		cout << CHILD_CLR << "CHILD - COPY CONSTRUCTOR\n" << RESET;
		ScavTrap	johnhy("ScavJohny");
		ScavTrap	jimmy(johnhy);
	}
	{
		printSeparator();
		cout << PARENT_CLR << "PARENT - COPY ASSIGNMENT OPERATOR\n" << RESET;
		ClapTrap	johnhy("Johny");
		ClapTrap	jimmy;
		jimmy = johnhy;
	}
	{
		printSeparator();
		cout << CHILD_CLR << "CHILD - COPY ASSIGNMENT OPERATOR\n" << RESET;
		ScavTrap	johnhy("ScavJohny");
		ScavTrap	jimmy;
		jimmy = johnhy;
	}
	{
		printSeparator();
		cout << PARENT_CLR << "PARENT - CLASS METHODS\n" << RESET;
		ClapTrap	Johnhy("Johny");
		Johnhy.attack("Molly");
		Johnhy.takeDamage(30);
	}
	{
		printSeparator();
		cout << CHILD_CLR << "CHILD - CLASS METHODS\n" << RESET;
		ScavTrap	scavJohnhy("ScavJohny");
		scavJohnhy.attack("Molly");
		scavJohnhy.takeDamage(30);
		scavJohnhy.guardGate();
		scavJohnhy.guardGate();
		scavJohnhy.guardGate();
	}
	printSeparator();
	return 0;
}
