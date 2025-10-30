#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
//# include "Bureaucrat.hpp"
# include "utils.hpp"

class Bureaucrat;

class Form {

	private:
		std::string const	name_;
		bool				isSigned_;
		const int			gradeToSign_;
		const int			gradeToExecute_;

		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;

	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();


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

		std::string 	getName( void ) const;
		bool			getIsSigned( void ) const;
		int 			getGradeToSign( void ) const;
		int 			getGradeToExecute( void ) const;

		void beSigned(Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream & os, Form const &other);

#endif
