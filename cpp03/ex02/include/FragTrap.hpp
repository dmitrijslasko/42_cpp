#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool _guardGateMode;

	public:
		ScavTrap();                         // Default constructor
		ScavTrap(std::string name);         // ✅ Add this
		ScavTrap(const ScavTrap &other);    // Copy constructor
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void guardGate();
};

#endif
