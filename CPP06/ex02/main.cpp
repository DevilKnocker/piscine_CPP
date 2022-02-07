#include "BaseClasses.hpp"

int main()
{
	Base* base = generate();
	identify(base);

	std::cout << "--------------------------" << std::endl;

	identify(*base);
}