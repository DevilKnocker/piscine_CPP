#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	
}

Zombie::~Zombie(){

	std::cout << this->name << "got shot in the head" << std::endl;
}

void Zombie::announce( void ) const{

	std::cout << this->name << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* zombieHorde( int N, std::string name ){

	Zombie* Horde = new Zombie
}