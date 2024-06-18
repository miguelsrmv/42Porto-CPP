#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int hit_points, int energy_points, unsigned int attack_data) : hit_points (hit_points), energy_points (energy_points), attack_data (attack_data)
{
	std::cout << "Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy constructor has been called" <, std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called" << std::endl;
}
