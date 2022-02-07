#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target){

	setName("PresidentialPardonForm");
	setTarget(target);
	setSigned(false);
	setGradetoSign(25);
	setGradetoExec(5);
}

PresidentialPardonForm::PresidentialPardonForm(){

	setName("PresidentialPardonForm");
	setSigned(false);
	setGradetoSign(25);
	setGradetoExec(5);
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		setName("PresidentialPardonForm");
		setSigned(rhs.getSigned());
		setGradetoSign(rhs.getGradetoSign());
		setGradetoExec(rhs.getGradetoExec());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << i.getName() << "form is ";
	if (i.getSigned() == 0)
		std::cout << "not signed, it requires a grade of ";
	else
		std::cout << "signed, it required a grade of ";
	std::cout << i.getGradetoSign() << " to sign, and requires a grade of " <<
	i.getGradetoExec() << " to execute";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::action() const{

	std::cout << getTarget() << " was forgiven by Zafod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */