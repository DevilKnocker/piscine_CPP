#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain(){

	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain & src ){

	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain(){

	std::cout << "Brain destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		int i = -1;

		while(++i < 100)
			setidea(i, rhs.getidea(i));
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getidea(int i) const{

	return (_ideas[i]);
}

void	Brain::setidea(int i, std::string idea){

	_ideas[i] = idea;
}
/* ************************************************************************** */