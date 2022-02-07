#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("GradeTooHighException : Form Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("GradeTooLowException : Form Grade too low or bureaucrat trying to sign with too low grade");
				}
		};


		Form(std::string name, int gradetosign, int gradetoexec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string getName() const;
		bool getSigned() const;
		int getGradetoSign() const;
		int getGradetoExec() const;

		bool beSigned(Bureaucrat);

	protected:

		Form();
	
	private:

	std::string const _name;
	bool _signed;
	int	const _grade_to_sign;
	int const _grade_to_exec;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */