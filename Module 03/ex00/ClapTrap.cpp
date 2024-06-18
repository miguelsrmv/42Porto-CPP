#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, unsigned int attack_data) : name(name), hit_points (hit_points), energy_points (energy_points), attack_data (attack_data)
{
	std::cout << "Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy constructor has been called" << std::endl;
}

ClapTrap &
ClapTrap::operator= (const ClapTrap &copy)
{
	if (this == &copy)
		return (*this);
	this->hit_points = copy.hit_points;
	this->attack_data = copy.attack_data;
	this->energy_points = copy.energy_points;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called" << std::endl;
}

void
ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_data << " points of damage!" << std::endl ;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " took " << amount << " points of damange!" << std::endl;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " healed for " << amount << " points of damange!" << std::endl;
}
