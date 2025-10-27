#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "utils.hpp"

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

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too low!";
				}
		};

		// Incremnt / Decrement operators
		//Bureaucrat &operator++();     // pre-increment (++a)
		//Bureaucrat operator++(int);   // post-increment (a++)
		//Bureaucrat &operator--();     // pre-decrement (--a)
		//Bureaucrat operator--(int);   // post-decrement (a--)

		std::string getName( void );
		int	getGrade( void );

		void increaseGrade( int amount );
		void decreaseGrade( int amount );
};

#endif
