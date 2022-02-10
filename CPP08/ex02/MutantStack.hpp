#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{

	public:

		typedef typename MutantStack<T>::container_type::iterator iterator;
		MutantStack() : std::stack<T>(){};
		MutantStack( MutantStack const & src ) : std::stack<T>(src){};
		~MutantStack(){};

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		MutantStack &		operator=( MutantStack const & rhs );

	private:

};
template<typename T>
std::ostream &			operator<<( std::ostream & o, MutantStack<T> const & i );

#endif /* ***************************************************** MUTANTSTACK_H */