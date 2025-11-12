#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "utils.hpp"
# include "AForm.hpp"

using std::exception;

class Intern {

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
