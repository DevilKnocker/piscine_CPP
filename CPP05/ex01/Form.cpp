#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(){

}

Form::Form(std::string name, int gradetosign, int gradetoexec){

	_name = name;
	_signed = 0;

	if (gradetosign > 150)
		throw(Form::GradeTooHighException());
	else if (gradetosign < 1)
		throw(Form::GradeTooLowException());
	else
		_grade_to_sign = gradetosign;

	if (gradetoexec > 150)
		throw(Form::GradeTooHighException());
	else if (gradetoexec < 1)
		throw(Form::GradeTooLowException());
	else
		_grade_to_exec = gradetoexec;
}

Form::Form( const Form & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(){

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_grade_to_sign = rhs.getGradetoSign();
		this->_grade_to_exec = rhs.getGradetoExec();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
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

bool Form::beSigned(Bureaucrat bur){

	if (_signed == true)
		return (false);
	else if (bur.getGrade() <= getGradetoSign())
	{
		_signed = true;
		return (true);
	}
	else
		throw(Form::GradeTooLowException());
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const{

	return (_name);
}

bool Form::getSigned() const{

	return (_signed);
}

int Form::getGradetoSign() const{

	return (_grade_to_sign);
}

int Form::getGradetoExec() const{

	return (_grade_to_exec);
}


/* ************************************************************************** */