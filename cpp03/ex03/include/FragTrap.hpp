#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	private:
		bool _guardGateMode;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);

		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		// new method
		void highFivesGuys( void );
};

#endif
