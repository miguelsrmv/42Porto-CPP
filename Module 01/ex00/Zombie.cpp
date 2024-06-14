#include "Zombie.hpp"

Zombie::Zombie (const std::string &name) : name (name) {}

Zombie::~Zombie ()
{
	std::cerr << "Log: " << name << " has been destroyed :(" << std::endl;
}

void
Zombie::announce (void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
