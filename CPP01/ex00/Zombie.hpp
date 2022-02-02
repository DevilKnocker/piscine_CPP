#include <iostream>


class Zombie {

	public :

		static Zombie* newZombie( std::string name );
		void announce( void ) const;
		static void randomChump( std::string name );
		void setName(std::string name);
		Zombie();
		~Zombie();
	private :

		std::string _name;		
};