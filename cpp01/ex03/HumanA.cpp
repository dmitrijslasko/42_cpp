# include <string>
# include "Weapon.hpp"
# include "HumanA.hpp"

// HumanA::HumanA( void ) {
// 	std::cout << "> HumanA.class default constructor called" << std::endl;
// }

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
	std::cout << "> HumanA.class parameterized constructor called" << std::endl;
}

HumanA::~HumanA( void ) {
	std::cout << "> HumanA.class destructor called" << std::endl;
}

void HumanA::attack( void ) {
	std::string weaponType = _weapon.getType();
	std::cout << _name << " attacks with their " << weaponType << std::endl;
}
