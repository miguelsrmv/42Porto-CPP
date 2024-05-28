#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"
#include <iostream>
#include <string>

int
main (void)
{
	std::cout << "Here's an example of a Zombie Heap!" << std::endl;

	Zombie *zombie_ptr1 = newZombie ("Alfred");
	Zombie *zombie_ptr2 = newZombie ("Bob");
	Zombie *zombie_ptr3 = newZombie ("Charles");

	std::cout << std::endl << std::endl;
	std::cout << "Here's an example of a Zombie Stack!" << std::endl;

	randomChump ("Diego");
	randomChump ("Edward");
	randomChump ("Fred");

	std::cout << std::endl << std::endl;
	std::cout << "And now the Heap gets deleted!" << std::endl;
	delete zombie_ptr1;
	delete zombie_ptr2;
	delete zombie_ptr3;
}
