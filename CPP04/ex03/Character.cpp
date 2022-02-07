#include "Character.hpp"

int Character::_inv_slot_max = 4;
int Character::_char_nb = 0;
Linklist Character::_lst = 0;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(){

}

Character::Character( std::string name){

	_name = name;
	_inv_slot_left = _inv_slot_max;
	_char_nb++;
}

Character::Character( const Character & src ){

	*this = src;
	_inv_slot_left = src._inv_slot_left;
	int i = 0;
	while (i < _inv_slot_max)
	{
		_materia_list[i] = src._materia_list[i];
		i++;
	}
	_char_nb++;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character(){

	std::cout << _char_nb << std::endl;
	_char_nb--;
	if (_char_nb == 0)
		_lst.empty();
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	//deep copy to patch
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Name = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m){

	if (m == 0)
	{
		std::cout << "You tried to equip an invalid materia" << std::endl;
		return ;
	}
	if (_inv_slot_left == 0)
	{
		std::cout << "No materia slot left, try to unequip some before" << std::endl;
		return ;
	}
	_materia_list[(_inv_slot_max - _inv_slot_left)] = m;
	std::cout << getName() << " equipped " << m->getType() 
	<< " in slot N°" << _inv_slot_max - _inv_slot_left + 1 << std::endl;
	
	_lst.add(m);
	_inv_slot_left--;
}

void Character::unequip(int idx){

	if (idx < 1 || idx > (_inv_slot_max - _inv_slot_left))
	{
		std::cout << "invalid slot number" << std::endl;
		return ;
	}
	std::cout << getName() << " unequipped " << _materia_list[idx - 1]->getType() <<
	" from slot N°" << idx << std::endl;
	_materia_list[idx - 1] = NULL;//liste chainee pour free a la fin necessaire
	_inv_slot_left++;
}

void Character::use(int idx, ICharacter& target){

	if (idx < 1 || idx > (_inv_slot_max - _inv_slot_left))
	{
		std::cout << "invalid slot number" << std::endl;
		return ;
	}
	std::cout << getName();
	_materia_list[idx - 1]->use(target);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const{

	return (_name);
}

/* ************************************************************************** */