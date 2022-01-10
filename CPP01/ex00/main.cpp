#include "Zombie.hpp"

int main (void)
{
	Zombie Stacktest("Stacktest");

	Stacktest.announce();

	Zombie* Heaptest = new Zombie("Heaptest");

	Heaptest->announce();
	delete Heaptest;

	Zombie::randomChump("Stack");

	Zombie* Heap = Zombie::newZombie("Heap");

	Heap->announce();
	delete Heap;
	
	std::cout << "FIN" << std::endl;
}