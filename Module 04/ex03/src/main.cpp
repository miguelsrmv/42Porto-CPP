#include "A_Materia.hpp"
#include "I_Character.hpp"
#include "Character.hpp"
#include "I_MateriaSource.hpp"
#include "Ice_Materia.hpp"
#include "Cure_Materia.hpp"

int
main (void)
{
	IMateriaSource *src = new MateriaSource ();
	src->learnMateria (new Ice ());
	src->learnMateria (new Cure ());

	ICharacter *me = new Character ("me");

	AMateria *tmp;
	tmp = src->createMateria ("ice");
	me->equip (tmp);
	tmp = src->createMateria ("cure");
	me->equip (tmp);

	ICharacter *bob = new Character ("bob");

	me->use (0, *bob);
	me->use (1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
