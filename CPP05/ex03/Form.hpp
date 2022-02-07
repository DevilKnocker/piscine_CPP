#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("NotSignedException : Form not signed cannot be executed");
				}
		};

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
					return ("GradeTooLowException : Form Grade too low or bureaucrat trying to sign/execute with too low grade");
				}
		};


		Form(std::string name, int gradetosign, int gradetoexec);
		Form( Form const & src );
		virtual ~Form();

		Form &		operator=( Form const & rhs );

		bool beSigned(Bureaucrat);
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;

		std::string getName() const;
		std::string getTarget() const;
		bool getSigned() const;
		int getGradetoSign() const;
		int getGradetoExec() const;

		void setTarget(std::string target);
		void setSigned(bool sign);
			

	protected:

		Form();
	
	private:

	std::string const _name;
	std::string _target;
	bool _signed;
	int	const _grade_to_sign;
	int const _grade_to_exec;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */