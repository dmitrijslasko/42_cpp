#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
		bool _guardModeOn;

		static const int DEFAULT_HP;
		static const int DEFAULT_EP;
		static const int DEFAULT_AD;

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
