# include <string>
# include "Weapon.hpp"
# include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	std::cout << "> HumanB.class default constructor called" << std::endl;
}

HumanB::HumanB( std::string name, Weapon* weapon ) : _name(name), _weapon(weapon)
{
	std::cout << "> HumanB.class parameterized constructor called" << std::endl;
}

HumanB::~HumanB( void ) {
	std::cout << "> HumanB.class destructor called" << std::endl;
}

void HumanB::attack( void ) {
	std::string weaponType = "";
	if (_weapon)
		weaponType = _weapon->getType();
	std::cout << _name << " attacks with their " << weaponType << std::endl;
}

void HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
}
