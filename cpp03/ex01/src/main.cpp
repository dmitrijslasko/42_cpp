#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main ( void ) {

	ClapTrap	johnhy = ClapTrap("johnny");
	ClapTrap	mikey = ClapTrap(johnhy);
	ClapTrap billy;
	billy = johnhy; // copy assignment

	johnhy.attack("jimmy");
	johnhy.beRepaired(2);
	johnhy.takeDamage(1);
	johnhy.takeDamage(15);
	johnhy.takeDamage(15);
	johnhy.takeDamage(15);
	johnhy.takeDamage(15);
	johnhy.beRepaired(15);
	mikey.attack("johnhy");
	billy.attack("johnhy");

	ScavTrap	tommy = ScavTrap("tommy");
	tommy.attack("winnie");
	tommy.takeDamage(20);
	tommy.beRepaired(50);

	return 0;
}
