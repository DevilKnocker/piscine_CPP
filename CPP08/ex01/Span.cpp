#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(unsigned int n) : _maxnb(n), _currentnb(0)
{
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		unsigned int i = 0;
		while (i < _currentnb)
		{
			this->_v.empty();
			this->_v.push_back(rhs._v.at(i));
			i++;
		}
		this->_maxnb = rhs._maxnb;
		this->_currentnb = rhs._currentnb;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n){

	if (_currentnb < _maxnb)
	{
		_v.push_back(n);
		_currentnb++;
	}
	else
		throw(TooManyArraysException());
}

void Span::addRange(unsigned int a, int b){

	if (_maxnb < _currentnb + a)
		throw(TooManyArraysException());
	std::vector<int> v(a, b);
	std::vector<int>::const_iterator it(v.begin());


	while (it != v.end())
	{
		addNumber(*it);
		it++;
	}
}

int Span::longestSpan() const{

	if(_currentnb < 2)
		throw(NotEnoughArraysException());
	std::vector<int>::const_iterator itb(_v.begin());
	std::vector<int>::const_iterator ite(_v.end());
	std::vector<int>::const_iterator itsavemin(_v.begin());
	std::vector<int>::const_iterator itsavemax(_v.begin());

	while (itb != ite)
	{
		if (*itsavemin > *itb)
			itsavemin = itb;
		if (*itsavemax < *itb)
			itsavemax = itb;
		itb++;
	}
	return (abs(*itsavemax - *itsavemin));

}

int Span::shortestSpan() const{

	if(_currentnb < 2)
		throw(NotEnoughArraysException());

	std::vector<int>::const_iterator itb1(_v.begin());
	std::vector<int>::const_iterator itb2;
	std::vector<int>::const_iterator ite(_v.end());
	int res;
	itb2 = itb1 + 1;
	int diff = abs(*itb1 - *itb2);

	while (itb1 != ite)
	{
		itb2 = itb1 + 1;
		while (itb2 != ite)
		{
			res = abs(*itb1 - *itb2);
			if (res < diff)
				diff = res;
			itb2++;
		}
		itb1++;
	}
	return (diff);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */