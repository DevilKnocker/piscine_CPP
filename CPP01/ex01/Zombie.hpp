#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>


class Zombie {

	public :

		void announce( void ) const;
		Zombie(std::string name);
		~Zombie();
	private :

		std::string name;		
};

#endif