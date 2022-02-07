#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat jeff("jeff", 1);
		ShrubberyCreationForm shrub("target");
		RobotomyRequestForm robo("target");
		PresidentialPardonForm pres("target");

		jeff.signForm(&shrub);
		jeff.signForm(&robo);
		jeff.signForm(&pres);
		jeff.executeForm(robo);
		jeff.executeForm(shrub);
		jeff.executeForm(pres);
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
	catch(Form::NotSignedException e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	catch(ShrubberyCreationForm::FileAlreadyExistException e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}


	std::cout << "no exception caught" << std::endl;
}