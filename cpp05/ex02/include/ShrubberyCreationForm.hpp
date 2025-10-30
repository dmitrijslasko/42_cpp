#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <string>
# include <iostream>

# include "utils.hpp"
# include "AForm.hpp"

class  ShrubberyCreationForm : public AForm {

	private:
		std::string 		target_;
		static const int	SIGN_GRADE = 145;
		static const int	EXEC_GRADE = 137;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

};

#endif
