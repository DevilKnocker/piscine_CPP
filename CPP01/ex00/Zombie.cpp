#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	
	this->_name = name;
}

Zombie::~Zombie(){

	std::cout << this->_name << " got shot in the head" << std::endl;
}

void Zombie::announce( void ) const{

	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){

	this->_name = name;
}