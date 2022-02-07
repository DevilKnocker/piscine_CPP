#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(){

	_type = "Cat";
	_brain = new Brain;
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat & src ){

	_brain = new Brain;
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(){

	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
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

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const{

	std::cout << "miaou miaou" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain* Cat::getbrain() const{

	return (_brain);
}

/* ************************************************************************** */