#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern(){
	
}

Intern::Intern( const Intern & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(){

}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	return *this;
	(void)rhs;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form* Intern::makepres(std::string target){

	return(new PresidentialPardonForm(target));
}

Form* Intern::makerobo(std::string target){

	return(new RobotomyRequestForm(target));
}

Form* Intern::makeshrub(std::string target){

	return(new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string formname, std::string targetname){

	std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	Form* (Intern::*fct[3])(std::string target) = {&Intern::makeshrub, &Intern::makerobo};
	int i = 0;

	while (i < 3)
	{
		if (formname.compare(tab[i]) == 0)
		{
			std::cout << "Intern creates " << formname << std::endl;
			return ((this->*fct[i])(targetname));
		}
		i++;
	}
	std::cout << "Invalid form name, form not created by Intern" <<std::endl;
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */