#include <iostream>
#include "Array.hpp"

int main()
{
	Array<std::string> a(2);
	Array<std::string> b;

	a[0] = "bonjour";
	a[1] = "aurevoir";

	b = a;
	b[0] = "coucou";

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
