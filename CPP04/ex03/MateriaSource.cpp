#include "MateriaSource.hpp"

int MateriaSource::_source_slot_max = 4;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource(){

	_source_slot_left = _source_slot_max;
}

MateriaSource::MateriaSource( const MateriaSource & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource(){

	int i = 0;

	while (i < _source_slot_max - _source_slot_left)
	{
			delete _source_list[i];
		i++;
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		int i = 0;
		while (i < _source_slot_max)
		{
			this->_source_list[i] = rhs._source_list[i];
			i++;
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria* m){

	if (_source_slot_max - _source_slot_left == 4)
	{
		std::cout << "No more room to stock that materia" << std::endl;
		return ;
	}
	_source_list[(_source_slot_max - _source_slot_left)] = m;
	std::cout << "The materia source now has " << m->getType() << " in slot N°" <<
	(_source_slot_max - _source_slot_left + 1) << std::endl;
	_source_slot_left--;
}

AMateria* MateriaSource::createMateria(std::string const & type){

	int i = 0;

	while (i < _source_slot_max - _source_slot_left)
	{
		if (type.compare(_source_list[i]->getType()) == 0)
			return (_source_list[i]->clone());
		i++;
	}
	std::cout << "no such materia in the materia source" << std::endl;
	return (0);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */