#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "utils.hpp"
# include "AForm.hpp"

using std::exception;

class Intern {

	// private:
	// 	std::string const	name_;
	// 	int					grade_;

	// 	static const int	HIGHEST_GRADE = 1;
	// 	static const int	LOWEST_GRADE = 150;

	public:
		Intern();
		Intern(const std::string &name, int grade);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm* makeForm(std::string const &formName, std::string const &formTarget);
};

// std::ostream &operator<<(std::ostream & os, Intern const &other);

#endif
