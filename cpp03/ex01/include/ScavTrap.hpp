#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
		bool _guardGateMode;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);

		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// Overridden method
		void attack(const std::string& target);

		// new method
		void guardGate();
};

#endif
