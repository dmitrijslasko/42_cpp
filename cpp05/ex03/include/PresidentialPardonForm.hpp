#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "utils.hpp"
# include "AForm.hpp"

class  PresidentialPardonForm : public AForm {

	private:
		std::string 		target_;

		static const int	SIGN_GRADE = 25;
		static const int	EXEC_GRADE = 5;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void 	setTarget(const std::string target);
		void 	beExecuted(const Bureaucrat &executor) const;
};

#endif
