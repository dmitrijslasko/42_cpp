#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "utils.hpp"

class Form {

	private:
		std::string const	name_;
		bool				isSigned_;
		const int			gradeToSign_;
		const int			gradeToExecute_;

	public:
		Form();
		Form(const std::string &name, int isSigned);
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

		void beSigned(Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream & os, Form const &other);

#endif
