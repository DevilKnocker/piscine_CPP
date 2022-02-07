#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "Linklist.hpp"

class Character : public ICharacter
{

	public:

		Character( Character const & src );
		Character( std::string name);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character &		operator=( Character const & rhs );
	
	protected:

		Character();
	
	private:

		std::string _name;
		int _inv_slot_left;
		static int _inv_slot_max;
		static int _char_nb;
		static Linklist _lst;
		AMateria* _materia_list[4]; //same nb as inv_slot_max
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */