#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat elon("elon", 0);
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat jeff("jeff", 150);
		std::cout << jeff << std::endl;
		jeff.decrement();
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "ended" << std::endl;
}