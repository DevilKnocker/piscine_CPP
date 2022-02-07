#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"

int main()
{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ce");
	me->equip(tmp);
	tmp = src->createMateria("cre");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(2, *bob);
	me->use(1, *bob);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std ::cout << "------------------------" << std::endl;

	
	std ::cout << "------------------------" << std::endl;

	ICharacter* copyme = new Character("copyme");
	copyme->use(0, *bob);
	me->use(0, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
	}