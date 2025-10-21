#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_damage = 30;
	std::cout << "FragTrap default constructor called\n";
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_damage = 30;
	std::cout << "FragTrap constructor called for " << _name << "\n";
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	_guardGateMode = other._guardGateMode;
	std::cout << "FragTrap copy constructor called\n";
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment called\n";
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardGateMode = other._guardGateMode;
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys( void ) {
	std::cout << B_MAGENTA;
	std::cout << "🙌 FragTrap " <<_name << " requests a high five!" << std::endl;
	std::cout << RESET;
}
