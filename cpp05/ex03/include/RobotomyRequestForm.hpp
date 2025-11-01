#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "utils.hpp"
# include "AForm.hpp"

class  RobotomyRequestForm : public AForm {

	private:
		std::string 		target_;

		static const int	SIGN_GRADE = 72;
		static const int	EXEC_GRADE = 45;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void 	setTarget(const std::string target);
		void 	beExecuted(const Bureaucrat &executor) const;
};

#endif
