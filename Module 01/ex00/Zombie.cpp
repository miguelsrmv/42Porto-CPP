#include "Zombie.hpp"

Zombie::Zombie (const std::string &name) : zombie_name (name) {}

Zombie::~Zombie ()
{
	std::cerr << "Log: " << zombie_name << " has died :(" << std::endl;
}

void
Zombie::announce (void) const
{
	std::cout << zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}