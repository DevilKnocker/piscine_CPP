#include "Zombie.hpp"

void Zombie::randomChump( std::string name ){

	Zombie ZombieCreate(name);

	ZombieCreate.announce();
}