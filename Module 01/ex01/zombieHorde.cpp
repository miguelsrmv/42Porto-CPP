#include "Zombie.hpp"

Zombie *
zombieHorde (int N, std::string name)
{
	if (N <= 0)
		{
			std::cerr << "Invalid N, please try again" << std::endl;
			return NULL;
		}
	else if (name.empty ())
		{
			std::cerr << "Invalid name, please try again" << std::endl;
			return NULL;
		}

	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_name (name);

	return (horde);
}
