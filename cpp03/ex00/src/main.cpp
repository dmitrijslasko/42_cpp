#include <iostream>
#include "ClapTrap.hpp"

using std::cout;

void	printSeparator( void ) {
	cout << "---------------------------------------------------------\n";
}

int	main ( void ) {
	{
		printSeparator();
		cout << B_CYAN << "DEFAULT CONSTRUCTOR\n" << RESET;
		ClapTrap	unnamed = ClapTrap();
	}
	{
		printSeparator();
		cout << B_CYAN << "PARAMETERIZED CONSTRUCTOR\n" << RESET;
		ClapTrap	johnhy("Johnny");

		for (int i = 0; i < 15; i++)
			johnhy.attack("Jimmy");
		johnhy.beRepaired(2);
		johnhy.takeDamage(1);
		johnhy.takeDamage(15);
		johnhy.takeDamage(15);
		johnhy.takeDamage(15);
		johnhy.takeDamage(15);
		johnhy.attack("Jimmy");
		johnhy.beRepaired(15);
	}
	{
		printSeparator();
		cout << B_CYAN << "COPY CONSTRUCTOR\n" << RESET;
		ClapTrap	johnhy("Johny");
		ClapTrap	jimmy(johnhy);
	}
	{
		printSeparator();
		cout << B_CYAN << "COPY ASSIGNMENT OPERATOR\n" << RESET;
		ClapTrap	johnhy("Johny");
		ClapTrap	jimmy;
		jimmy = johnhy;
	}
	printSeparator();
	return 0;
}
