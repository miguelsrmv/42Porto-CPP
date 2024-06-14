#include "Zombie.hpp"
#include <iostream>
#include <string>

int
main (void)
{
	std::cout << "Here's an example of a Zombie Heap!" << std::endl;

	Zombie *zombie_ptr1 = newZombie ("Alfred");
	Zombie *zombie_ptr2 = newZombie ("Bob");
	Zombie *zombie_ptr3 = newZombie ("Charles");

	zombie_ptr1->announce ();
	zombie_ptr2->announce ();
	zombie_ptr3->announce ();

	std::cout << std::endl
			  << std::endl
			  << "Here's an example of a Zombie Stack!" << std::endl;

	randomChump ("Diego");
	randomChump ("Edward");
	randomChump ("Fred");

	std::cout << std::endl
			  << std::endl
			  << "And now the Heap gets deleted!" << std::endl;

	delete zombie_ptr1;
	delete zombie_ptr2;
	delete zombie_ptr3;
}
