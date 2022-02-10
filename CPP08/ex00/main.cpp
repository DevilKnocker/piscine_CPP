#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> bar(3, 42);

	bar.at(1) = 50;
	std::cout << *easyfind(bar, 50) << std::endl;

	std::cout << *easyfind(bar, 500) << std::endl;
}