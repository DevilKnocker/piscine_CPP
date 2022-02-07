#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat jeff("jeff", 1);
		Form buildingrequest("buildingrequest", 150, 150);
		std::cout << jeff << std::endl;
		std::cout << buildingrequest << std::endl;
		jeff.signForm(&buildingrequest);
		jeff.increment();
		jeff.signForm(&buildingrequest);
		
		std::cout << "--------------------\n";
		
		ShrubberyCreationForm shrub("target");
		RobotomyRequestForm robo("target");
		PresidentialPardonForm pres("target");

		jeff.signForm(&shrub);
		jeff.signForm(&robo);
		jeff.signForm(&pres);
		jeff.executeForm(robo);
		jeff.executeForm(shrub);
		jeff.executeForm(pres);
		
		std::cout << "--------------------\n";

	
		Intern intern;
		Form* shrubby = intern.makeForm("ShrubberyCreationForm", "bobby");
		jeff.signForm(shrubby);
		jeff.executeForm(*shrubby);
		delete shrubby;
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