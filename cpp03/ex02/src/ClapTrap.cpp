#include "ClapTrap.hpp"

const int ClapTrap::DEFAULT_HP = 10;
const int ClapTrap::DEFAULT_EP = 10;
const int ClapTrap::DEFAULT_AD = 0;

// Constructor (default)
ClapTrap::ClapTrap()
	: _name("default"),
	  _hitPoints(DEFAULT_HP),
	  _energyPoints(DEFAULT_EP),
	  _attackDamage(DEFAULT_AD)
{
	std::cout << ">>> ClapTrap default constructor called" << std::endl;
}

// Constructor (parameterized)
ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(DEFAULT_HP),
	  _energyPoints(DEFAULT_EP),
	  _attackDamage(DEFAULT_AD)
{
	std::cout 	<< ">>> ClapTrap parameterized constructor called: "
				<< _name << " "
				<< _hitPoints << " "
				<< _energyPoints << " "
				<< _attackDamage
				<< std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << ">>> ClapTrap copy constructor called for " << _name << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << ">>> ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << ">>> ClapTrap destructor for " << _name << " called" << std::endl;
}

// Public methods
void ClapTrap::attack(const std::string& target) {

	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't attack " << target << ": not enough energy points!\n";
		return ;
	}

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't attack " << target << ": not enough hit points!\n";
		return ;
	}

	this->_energyPoints--;
	std::cout << B_YELLOW;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! "
				<< "Energy points: " << _energyPoints << "\n";
	std::cout << RESET;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << B_RED;
		std::cout << "ClapTrap " << _name << " already has 0 hit points. Stop hitting him!\n";
		std::cout << RESET;
		return ;
	}

	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;

	std::cout << B_CYAN;
	std::cout << "ClapTrap " << _name << " takes damage of " << amount << " points. Current hit points: " << this->_hitPoints << "\n";
	std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << B_RED;
		std::cout << "ClapTrap " << _name << " can't get repaired: not enough hit points!\n";
		std::cout << RESET;
		return ;
	}
	else if (this->_energyPoints == 0) {
		std::cout << B_RED;
		std::cout << "ClapTrap " << _name << " can't get repaired: not enough energy points!\n";
		std::cout << RESET;
		return ;
	}
	this->_hitPoints += amount;
	std::cout << B_GREEN;
	std::cout << "ClapTrap " << _name << " got repaired for " << amount  << " points. Current hit points: " << this->_hitPoints << "\n";
	std::cout << RESET;
}
