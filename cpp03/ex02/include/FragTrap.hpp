#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	private:

		static const int DEFAULT_HP;
		static const int DEFAULT_EP;
		static const int DEFAULT_AD;

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
