#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat jeff("jeff", 149);
		Form buildingrequest("buildingrequest", 149, 149);
		std::cout << jeff << std::endl;
		std::cout << buildingrequest << std::endl;
		jeff.signForm(&buildingrequest);
		jeff.increment();
		jeff.signForm(&buildingrequest);
		Bureaucrat bobby("bobby", 150);
		Form changemayorrequest("changemayorrequest", 1, 1);
		bobby.signForm(&changemayorrequest);
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
	catch(Form::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	catch(Form::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}


	std::cout << "ended" << std::endl;
}