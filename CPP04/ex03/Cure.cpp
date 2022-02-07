#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure(){

	setType("cure");
}

Cure::Cure( const Cure & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cure const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cure::use(ICharacter& target){

	std::cout << " *heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const{

	Cure* cure = new Cure;
	return cure;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */