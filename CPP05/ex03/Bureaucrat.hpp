#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("GradeTooHighException : Bureaucrat Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("GradeTooLowException : Bureaucrat Grade too low");
			}
		};


		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();

		void signForm(Form*);
		void executeForm(Form const & form) const;

		Bureaucrat &		operator=( Bureaucrat const & rhs );

	protected:

		Bureaucrat();

	private:

	const std::string _name;
	int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */