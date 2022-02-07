#include "RobotomyRequestForm.hpp"
#include <time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target){

	setName("RobotomyRequestForm");
	setTarget(target);
	setSigned(false);
	setGradetoSign(72);
	setGradetoExec(45);
}

RobotomyRequestForm::RobotomyRequestForm(){

	setName("RobotomyRequestForm");
	setSigned(false);
	setGradetoSign(72);
	setGradetoExec(45);
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		setName("RobotomyRequestForm");
		setSigned(rhs.getSigned());
		setGradetoSign(rhs.getGradetoSign());
		setGradetoExec(rhs.getGradetoExec());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
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

void	RobotomyRequestForm::action() const{

	int i;
	
	std::cout << "*DRILL NOISES*" << std::endl;
	srand (time(NULL));
	i = rand() % 2;
	if (i == 1)
		std::cout << getTarget() << " Has succesfully been robotomized" << std::endl;
	else
		std::cout << "FAILURE : " << getTarget() << " Was not robotomized" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */