#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie* ZombieCreate = new Zombie(name);
	
	return (ZombieCreate);
}