#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(){

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){

	if (grade > 150)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooLowException());
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName()){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat(){

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o  << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increment(){

	if (_grade == 1)
	{
		std::cout << getName() << " already has maximum grade" << std::endl;
		return ;
	}
	_grade--;
}

void Bureaucrat::decrement(){

	if (_grade == 150)
	{
		std::cout << getName() << " already has minimum grade" << std::endl;
		return ;
	}
	_grade++;
}

void Bureaucrat::signForm(Form* form){

	if (form->getSigned() == false && form->beSigned(*this) == true)
		std::cout << "Bureaucrat " << getName() << " has signed form " << form->getName() <<
		std::endl;
	else
		std::cout << "Bureaucrat " << getName() << " could not sign form " <<
		form->getName() << " as it was already signed" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const{

	return(_name);
}

int Bureaucrat::getGrade() const{

	return(_grade);
}

/* ************************************************************************** */