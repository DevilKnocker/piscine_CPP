#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat jeff("jeff", 150);
		jeff.decrement();
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}

	std::cout << "no exception caught" << std::endl;
}