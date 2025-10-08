#ifndef HARL_H
# define HARL_H

# include <string>

# define DEFAULT 	"\033[0m"
# define B_GREEN	"\033[1;92m"
# define B_YELLOW	"\033[1;93m"
# define B_ORANGE	"\033[1;38;5;208m"
# define B_RED		"\033[1;38;5;210m"

class Harl {
	public:
		// 1. Constructors
		Harl();                   	// default constructor
		// Harl( std::string name );		// parameterized constructor

		// 2. Destructor
		~Harl();

		// 3. Public member functions
		void complain( std::string level );
		
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
