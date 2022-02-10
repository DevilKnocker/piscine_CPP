#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <iterator>
# include <stdexcept>

class Span
{

	class NotEnoughArraysException : std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Need at least 2 arrays to call that function");
		}
	};

	class TooManyArraysException : std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Can't add anymore arrays in class Span");
		}
	};

	public:

		Span(unsigned int n);
		Span( Span const & src );
		~Span();

		void addNumber(int n);
		void addRange(unsigned int a, int b);
		int shortestSpan() const;
		int longestSpan() const;

		Span &		operator=( Span const & rhs );

	protected:
		
		Span();
	
	private:

		std::vector<int> _v;
		unsigned int _maxnb;
		unsigned int _currentnb;
};


#endif /* ************************************************************ SPAN_H */