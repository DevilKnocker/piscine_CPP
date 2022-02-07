#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(){

	_type = "Dog";
	_brain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog & src ){

	_brain = new Brain;
	*this =src;
	std::cout << "Dog copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(){

	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		int i = -1;

		while(++i < 100)
			getbrain()->setidea(i, rhs.getbrain()->getidea(i));
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const{

	std::cout << "bark bark" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain* Dog::getbrain() const{

	return (_brain);
}


/* ************************************************************************** */