#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template<typename T>
class Array
{

	class BadIndexException : public std::exception
	{
		public :
				virtual const char* what() const throw()
				{
					return ("Exception caught : Bad index !");
				}
	};

	public:

		Array();
		Array(unsigned int arg);
		Array( Array const & src );
		~Array();

		void asd();

		unsigned int size() const;
		T & getElement(unsigned int i) const;

		Array &		operator=( Array const & rhs );
		T &		operator[](unsigned int i);

	private:

		T* _element;
		unsigned int _size;
};
template<typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i );

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
template<typename T>
Array<T>::Array(){

	_element = new T;
	_size = 0;
	std::cout << "created empty array" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int arg){

	_size = arg;
	if (arg > 0)
	{
		_element = new T[arg];
		std::cout << "created " << arg << " arrays" << std::endl;
	}
	else
	{
		_element = new T;
		std::cout << "created empty array" << std::endl;
	}
}

template<typename T>
Array<T>::Array( const Array & src ){

	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
template<typename T>
Array<T>::~Array(){

	if (_size == 0)
	{
		delete _element;
		std::cout << "destroyed empty array" << std::endl;
	}
	else
	{
		delete [] _element;
		std::cout << "destroyed " << _size << " array" << std::endl;
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
template<typename T>
Array<T> &				Array<T>::operator=( Array<T> const & rhs )
{
	if ( this != &rhs )
	{

		if (_size == 0)
		{
			delete _element;
			std::cout << "destroyed empty array" << std::endl;
		}
		else
		{
			delete [] _element;
			std::cout << "destroyed " << _size << " array" << std::endl;
		}


		if (rhs.size())
		{
			_element = new T[rhs.size()];
			std::cout << "created " << rhs.size() << " arrays" << std::endl;
		}
		else
		{
			_element = new T;
			std::cout << "created empty array" << std::endl;
		}


		_size = rhs.size();
		unsigned int i = 0;
		while (i < _size)
		{
			this->_element[i] = rhs.getElement(i);
			i++;
		}

	}
	return *this;
}

template<typename T>
T &		Array<T>::operator[](unsigned int i){

	return (getElement(i));
}

template<typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i )
{
	unsigned int u = 0;

	while (u < i.size())
	{
		o << i.getElement(u) << " ";
		u++;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/




/*
** --------------------------------- ACCESSOR ---------------------------------
*/

template<typename T>
unsigned int Array<T>::size() const {

	return (_size);
}

template<typename T>
T &Array<T>::getElement(unsigned int i) const{

	if (i < _size)
		return (_element[i]);
	throw(Array::BadIndexException());
}

/* ************************************************************************** */

#endif /* *********************************************************** ARRAY_H */