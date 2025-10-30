#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "utils.hpp"

class Bureaucrat;

class AForm {

	private:
		std::string const	name_;
		bool				isSigned_;
		const int			gradeToSign_;
		const int			gradeToExecute_;

		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;

	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		// member functions
		// getters and setters
		std::string 	getName( void ) const;
		bool			getIsSigned( void ) const;
		int 			getGradeToSign( void ) const;
		int 			getGradeToExecute( void ) const;

		// methods
		void 	beSigned(const Bureaucrat &bureaucrat);
		virtual void 	beExecuted(const Bureaucrat &bureaucrat);

				// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream & os, AForm const &other);

#endif
