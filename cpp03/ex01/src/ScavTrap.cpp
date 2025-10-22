#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGateMode = false;
	std::cout << "ScavTrap default constructor called\n";
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
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
		ClapTrap::operator=(other);
		_guardGateMode = other._guardGateMode;
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

// Overridden attack method
void ScavTrap::attack(const std::string& target) {

	if (this->_energyPoints && this->_hitPoints) {
		std::cout << B_YELLOW;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
		std::cout << RESET;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " can't attack " << target << ": not enough energy points!\n";
	else
		std::cout << "ScavTrap " << _name << " can't attack " << target << ": not enough hit points!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap guardGate() method called" << std::endl;
	if (this->_guardGateMode == 0)
	{
		std::cout << B_MAGENTA;
		std::cout << "✅ Guard keeper mode for " <<_name << " activated!" << std::endl;
		std::cout << RESET;
		_guardGateMode = 1;
	}
	else
	{
		std::cout << B_MAGENTA;
		std::cout << "❌ Guard keeper mode for " <<_name << " deactivated!" << std::endl;
		std::cout << RESET;
		_guardGateMode = 0;
	}
}
