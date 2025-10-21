#include "ClapTrap.hpp"

// Constructor (default)
ClapTrap::ClapTrap()
	: _name("default"),
	  _hit_pts(10),
	  _energy_pts(10),
	  _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Constructor (parameterized)
ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hit_pts(10),
	  _energy_pts(10),
	  _attack_damage(0)
{
	std::cout 	<< "ClapTrap parameterized constructor called: "
				<< _name << " " 
				<< _hit_pts << " " 
				<< _energy_pts << " " 
				<< _attack_damage 
				<< std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	  _hit_pts(other._hit_pts),
	  _energy_pts(other._energy_pts),
	  _attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_damage = other._attack_damage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

// Public methods
void ClapTrap::attack(const std::string& target) {
	if (this->_energy_pts && this->_hit_pts) {
		std::cout << B_YELLOW;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
		std::cout << RESET;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "ClapTrap " << _name << " can't attack " << target << ": not enough energy points!\n";
	else
		std::cout << "ClapTrap " << _name << " can't attack " << target << ": not enough hit points!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	
	if (this->_hit_pts > amount)
		this->_hit_pts -= amount;
	else if (this->_hit_pts > 0)
		this->_hit_pts = 0;
	else {
		std::cout << B_RED;
		std::cout << "ClapTrap " << _name << " already has 0 hit points. Stop hitting him!\n";
		std::cout << RESET;
		return ;
	}
	std::cout << B_CYAN;
	std::cout << "ClapTrap " << _name << " takes damage of " << amount  << " points. Current hit points: " << this->_hit_pts << "\n";
	std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_pts == 0) {
		std::cout << B_RED;
		std::cout << "ClapTrap " << _name << " can't get repaired: not enough energy points!\n";
		std::cout << RESET;
		return ;
	}
	else if (this->_hit_pts == 0) {
		std::cout << B_RED;
		std::cout << "ClapTrap " << _name << " can't get repaired: not enough hit points!\n";
		std::cout << RESET;
		return ;
	}
	this->_hit_pts += amount;
	std::cout << B_GREEN;
	std::cout << "ClapTrap " << _name << " got repaired for " << amount  << " points. Current hit points: " << this->_hit_pts << "\n";
	std::cout << RESET;
}
