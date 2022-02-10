#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

Span sp2(100);
sp2.addRange(100, 42);
std::cout << sp2.shortestSpan() << std::endl;
std::cout << sp2.longestSpan() << std::endl;
return 0;
}