#include "Zombie.hpp"
#include "zombieHorde.cpp"
#include <iostream>
#include <string>

int
main (void)
{
	Zombie *horde;

	// Normal usage
	horde = zombieHorde (5, "Mr. Goodheart");
	for (int i = 0; i < 5; i++)
		{
			std::cout << "(" << i + 1 << ") ";
			horde[i].announce ();
		}
	delete[] horde;

	std::cout << std::endl;
	// Invalid usage
	/// Invalid number
	horde = zombieHorde (0, "Mr. Goodheart");
	horde = zombieHorde (-1, "Mr. Goodheart");
	/// When casting non-ints, these won't even compile
	///	horde = zombieHorde(NULL, "Mr. Goordheart");
	//// horde = zombieHorde("a", "Mr. Goodheart");
	//// horde = zombieHorde('a', "Mr. Goodheart");

	/// No name
	horde = zombieHorde (5, "");

	/// Without enough arguments, it won't even compile
	//// horde = zombieHorde(5);
	//// horde = zombieHorde(void);

	/// This would crash without changing the function signature or overloading
	/// the function
	//// horde = zombieHorde(5, NULL);
}
