#include <iostream>
#include "ClapTrap.hpp"

int	main ( void ) {

	ClapTrap	johnhy = ClapTrap("johnny");
	ClapTrap	mikey = ClapTrap(johnhy);
	ClapTrap billy;
	billy = johnhy;

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

	return 0;
}
