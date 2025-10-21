#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main ( void ) {

	ScavTrap	johnhy = ScavTrap("johnny");
	ScavTrap	mikey = ScavTrap(johnhy);
	ScavTrap billy;
	billy = johnhy; // copy assignment

	johnhy.attack("jimmy");
	johnhy.beRepaired(2);
	johnhy.takeDamage(1);
	johnhy.takeDamage(15);
	johnhy.takeDamage(15);
	johnhy.takeDamage(15);
	johnhy.takeDamage(15);
	johnhy.beRepaired(15);
	johnhy.guardGate();
	mikey.attack("johnhy");
	billy.attack("johnhy");
	johnhy.guardGate();

	ScavTrap	tommy = ScavTrap("tommy");
	tommy.attack("winnie");
	tommy.takeDamage(20);
	tommy.beRepaired(50);

	return 0;
}
