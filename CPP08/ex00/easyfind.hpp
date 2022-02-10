#include <stdexcept>

class NotFoundException : public std::exception{

	public :
	virtual const char* what() const throw()
	{
		return ("Occurence not found");
	}
};

template<typename T>
typename T::const_iterator easyfind(T const & a, int const b){

	typename T::const_iterator iterbegin(a.begin());
	typename T::const_iterator iterend(a.end());
	while (iterbegin != iterend)
	{
		if (*iterbegin == b)
			return (iterbegin);
		iterbegin++;
	}
	throw(NotFoundException());
}