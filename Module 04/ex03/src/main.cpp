#include "A_Materia.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "I_Character.hpp"
#include "I_MateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

void
subject_tests ()
{
	std::cout << "MAIN TESTS" << std::endl << std::endl;

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

	std::cout << std::endl;
}

void
deep_copy_tests ()
{
	std::cout << "DEEP COPY TESTS" << std::endl << std::endl;

	Character *bob = new Character ("Bob");
	Character *me = new Character (*bob);

	// Print the addresses of bob and me
	std::cout << "---------------------------" << std::endl;
	std::cout << "Address of Bob: " << bob << std::endl;
	std::cout << "Address of Me: " << me << std::endl;
	std::cout << "---------------------------" << std::endl;

	IMateriaSource *source = new MateriaSource ();
	source->learnMateria (new Ice ());
	source->learnMateria (new Cure ());
	Ice *ice = new Ice ();
	Ice *iceCopy = new Ice (*ice);
	Cure *cure = new Cure ();
	Cure *cureCopy = new Cure (*cure);

	// Print the addresses of Ice / IceCopy and Cure / CureCopy
	std::cout << "---------------------------" << std::endl;
	std::cout << "Address of Ice: " << ice << std::endl;
	std::cout << "Address of Ice copy: " << iceCopy << std::endl;
	std::cout << "Address of Cure: " << cure << std::endl;
	std::cout << "Address of Cure copy: " << cureCopy << std::endl;
	std::cout << "---------------------------" << std::endl;

	// Delete allocated memory
	delete bob;
	delete me;
	delete source;
	delete ice;
	delete iceCopy;
	delete cure;
	delete cureCopy;

	std::cout << std::endl;
}

void
materia_usage_tests ()
{
	std::cout << "MATERIA USAGE TEST" << std::endl << std::endl;

	IMateriaSource *src = new MateriaSource ();
	for (int idx = 0; idx < 4; idx++)
		src->learnMateria (new Cure ());

	AMateria *tmp[6];
	for (int idx = 0; idx < 6; idx++)
		tmp[idx] = src->createMateria ("cure");

	Character *me = new Character ("me");

	// Attempt to learn the 5th materia
	std::cout << "Test #1:" << std::endl;
	Ice *excess_materia = new Ice ();
	src->learnMateria (excess_materia);

	// Attempts creating unlearned materia
	std::cout << std::endl << "Test #2:" << std::endl;
	AMateria *invalid_materia = src->createMateria ("fire");

	// Attempts unequipping when there's no materia equipped yet
	std::cout << std::endl << "Test #3:" << std::endl;
	for (int idx = 0; idx < 4; idx++)
		me->unequip (idx);

	// Tests what happens when you attempt to equip the 5th materia
	std::cout << std::endl << "Test #4:" << std::endl;
	for (int idx = 0; idx < 5; idx++)
		me->equip (tmp[idx]);

	// Tests unequipping invalid indexes
	std::cout << std::endl << "Test #5.1:" << std::endl;
	me->unequip (5);
	std::cout << std::endl << "Test #5.2:" << std::endl;
	me->unequip (-1);

	// Unequips one materia, then attempts to equip another one back
	// (should work!)
	std::cout << std::endl << "Test #6 (should print nothing): " << std::endl;
	me->unequip (0);
	me->equip (tmp[4]);

	// Re-tests over-adding materia
	std::cout << std::endl << "Test #7:" << std::endl;
	me->equip (tmp[5]);

	// Attempts using materia above/below valid indices
	std::cout << std::endl << "Test #8.1:" << std::endl;
	me->use (-1, *me);
	std::cout << std::endl << "Test #8.2:" << std::endl;
	me->use (4, *me);


	// Unequips all materia (for valgrind purposes)
	for (int idx = 0; idx < 4; idx++)
		me->unequip (idx);

	// Delete allocated memory
	for (int idx = 0; idx < 6; idx++)
		delete tmp[idx];
	delete invalid_materia;
	delete excess_materia;
	delete src;
	delete me;

	std::cout << std::endl;
}

int
main (void)
{
	std::cout << std::endl;

	subject_tests ();
	deep_copy_tests ();
	materia_usage_tests ();
	return 0;
}
