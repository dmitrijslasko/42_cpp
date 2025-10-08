#include "Weapon.hpp"


Weapon::Weapon( void ) {
	std::cout << "> Weapon.class default constructor called" << std::endl;
}

Weapon::Weapon( std::string type ) : _type(type) {
	std::cout << "> Weapon.class parameterized constructor called" << std::endl;
}

Weapon::~Weapon( void ) {
	std::cout << "> Weapon.class destructor called" << std::endl;
}

void Weapon::setType( std::string type ) {
	_type = type;
}

std::string& Weapon::getType( void ) {
	return _type;
}
