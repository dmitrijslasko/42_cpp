#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_damage = 20;
	_guardGateMode = false;
	std::cout << "ScavTrap default constructor called\n";
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_damage = 20;
	_guardGateMode = false;
	std::cout << "ScavTrap constructor called for " << _name << "\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	_guardGateMode = other._guardGateMode;
	std::cout << "ScavTrap copy constructor called\n";
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment called\n";
	if (this != &other) {
		ClapTrap::operator=(other); // reuse parent logic
		_guardGateMode = other._guardGateMode;
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap guardGate() method called" << std::endl;
	if (this->_guardGateMode == 0)
		_guardGateMode = 1;
	else
		_guardGateMode = 0;
}
