#include "ScavTrap.hpp"

const int ScavTrap::DEFAULT_HP = 100;
const int ScavTrap::DEFAULT_EP = 50;
const int ScavTrap::DEFAULT_AD = 20;

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = DEFAULT_HP;
	_energyPoints = DEFAULT_EP;
	_attackDamage = DEFAULT_AD;
	_guardModeOn = false;
	std::cout << ">> ScavTrap default constructor called\n";
}

// Parameterized constructorconst int ClapTrap::DEFAULT_HP = 10;
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = DEFAULT_HP;
	_energyPoints = DEFAULT_EP;
	_attackDamage = DEFAULT_AD;
	_guardModeOn = false;
	std::cout << ">> ScavTrap constructor called for " << _name << "\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	_guardModeOn = other._guardModeOn;
	std::cout << ">> ScavTrap copy constructor called\n";
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << ">> ScavTrap copy assignment called\n";
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardModeOn = other._guardModeOn;
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << ">> ScavTrap destructor called\n";
}

// Overridden attack method
void ScavTrap::attack(const std::string& target) {

	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " can't attack " << target << ": not enough energy points!\n";
		return ;
	}

	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " can't attack " << target << ": not enough hit points!\n";
		return ;
	}

	this->_energyPoints--;
	std::cout << B_YELLOW;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! "
				<< "Energy points: " << _energyPoints << "\n";
	std::cout << RESET;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap guardGate() method called" << std::endl;
	if (this->_guardModeOn == 0)
	{
		std::cout << B_MAGENTA;
		std::cout << "✅ Guard keeper mode for " <<_name << " activated!" << std::endl;
		std::cout << RESET;
		_guardModeOn = 1;
	}
	else
	{
		std::cout << B_MAGENTA;
		std::cout << "❌ Guard keeper mode for " <<_name << " deactivated!" << std::endl;
		std::cout << RESET;
		_guardModeOn = 0;
	}
}
