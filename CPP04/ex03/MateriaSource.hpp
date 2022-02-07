#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
	
		int _source_slot_left;
		static int _source_slot_max;
		AMateria* _source_list[4]; //same nb as source_slot_max
};

#endif /* *************************************************** MATERIASOURCE_H */