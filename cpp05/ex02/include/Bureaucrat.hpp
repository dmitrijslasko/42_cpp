#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "utils.hpp"
# include "AForm.hpp"

using std::exception;

class Bureaucrat {

	private:
		std::string const	name_;
		int					grade_;

		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Exceptions
		class GradeTooHighException : public exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public exception
		{
			public:
				const char *what() const throw();
		};

		std::string getName( void ) const;
		int			getGrade( void ) const;

		void incrementGrade( int amount );
		void decrementGrade( int amount );

		int signForm( AForm &form );
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);

#endif
