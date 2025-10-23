#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {

	protected:
		// Name, which is passed as a parameter to the constructor
		std::string		_name;
		// Hit points (10), representing the health of the ClapTrap
		unsigned int	_hitPoints;
		// Energy points (10)
		unsigned int	_energyPoints;
		// Attack damage (0)
		unsigned int	_attackDamage;

		static const int DEFAULT_HP;
		static const int DEFAULT_EP;
		static const int DEFAULT_AD;

	public:
		// Constructor (default)
		ClapTrap();

		// Constructor (parameterized)
		ClapTrap(std::string name);

		// Copy constructor
		ClapTrap(const ClapTrap &other);

		// Copy assignment operator
		ClapTrap &operator=(const ClapTrap &other);

		// Destructor
		virtual ~ClapTrap();

		// Public methods
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

// terminal Colors (ANSI Escape Codes)
# define	BLACK			"\033[30m"
# define	GREY			"\033[90m"
# define	RED				"\033[31m"
# define	GREEN			"\033[32m"
# define	YELLOW			"\033[33m"
# define	BLUE			"\033[34m"
# define	MAGENTA			"\033[35m"
# define	CYAN			"\033[36m"
# define	WHITE			"\033[37m"
# define	B_BLACK			"\033[90m"
# define	B_RED			"\033[38;5;210m"
# define	B_GREEN			"\033[92m"
# define	B_YELLOW		"\033[93m"
# define	B_BLUE			"\033[94m"
# define	B_MAGENTA		"\033[95m"
# define	B_CYAN			"\033[96m"
# define	B_WHITE			"\033[97m"
# define 	RESET			"\033[0m"

#endif
