#include "Linklist.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Linklist::Linklist():_first (NULL), _count(0){

}

Linklist::Linklist (int const & value){
	
	(void)value;
	_first = NULL;
	_count = 0;
}
Linklist::Linklist( const Linklist & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Linklist::~Linklist()
{
	Node* next;
	Node* current;

	current = _first;
	while (current)
	{
		next = current->next;
		delete current->data;
		delete current;
		current = next;
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Linklist &				Linklist::operator=( Linklist const & rhs )
{
	if ( this != &rhs )
	{
		Node* next;
		Node* current;

		current = _first;
		while (current)
		{
			next = current->next;
			this->add(current->data);
			current = next;
		}
	}
	return *this;
}

Linklist &				Linklist::operator=( int const & value )
{
	(void)value;
	_first = NULL;
	_count = 0;
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Node* Linklist::CreateNode (AMateria* value){

	Node* tmp = new Node;
	tmp->data = value;
	tmp->next = NULL;
	return (tmp);
}

void Linklist::empty (){

	Node* next;
	Node* current;

	current = _first;
	while (current)
	{
		next = current->next;
		delete current->data;
		delete current;
		current = next;
	}
	_first = NULL;
	_count = 0;
}

void Linklist::add (AMateria* value){

	Node* tmp;

	if (_count == 0)
	{
		_first = CreateNode(value);
	}
	else
	{
		tmp = _first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = CreateNode(value);
	}
	_count++;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */