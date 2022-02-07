#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(){

	setType("ice");
}

Ice::Ice( const Ice & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Ice::use(ICharacter& target){

	std::cout << " *shoots an ice bolt at " << target.getName() <<
	"*" << std::endl;;
}

AMateria* Ice::clone() const{

	Ice* ice = new Ice;
	return ice;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */