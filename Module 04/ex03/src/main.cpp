#include "A_Materia.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "I_Character.hpp"
#include "I_MateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>


void deep_copy_tests() {
    std::cout << "DEEP COPY TESTS" << std::endl << std::endl;

    Character *bob = new Character("Bob");
    Character *me = new Character(*bob);

    // Print the addresses of bob and me
    std::cout << "---------------------------" << std::endl;
    std::cout << "Address of Bob: " << bob << std::endl;
    std::cout << "Address of Me: " << me << std::endl;
    std::cout << "---------------------------" << std::endl;

    // Delete allocated memory
    delete bob;
    delete me;

    std::cout << std::endl;
}

void subject_tests()
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

	std::cout << std::endl ;
}

int
main (void)
{
	subject_tests();
	deep_copy_tests();
	return 0;
}
