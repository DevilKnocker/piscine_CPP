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
		Intern intern;
		Form* shrubby = intern.makeForm("ShrubberyCreationForm", "bobby");
		Form* roby = intern.makeForm("RobotomyRequestForm", "bobby");
		Form* presy = intern.makeForm("PresidentialPardonForm", "bobby");
		jeff.signForm(shrubby);
		jeff.executeForm(*shrubby);
		jeff.signForm(roby);
		jeff.executeForm(*roby);
		jeff.signForm(presy);
		jeff.executeForm(*presy);
		delete shrubby;
		delete roby;
		delete presy;
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