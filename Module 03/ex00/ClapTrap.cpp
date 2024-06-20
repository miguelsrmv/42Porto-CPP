#include "ClapTrap.hpp"

ClapTrap::ClapTrap (std::string name)
	: name (name), hit_points (10), energy_points (10), attack_data (0)
{
	std::cout << "Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy constructor has been called" << std::endl;
}

ClapTrap &
ClapTrap::operator= (const ClapTrap &copy)
{
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->attack_data = copy.attack_data;
	this->energy_points = copy.energy_points;
	return (*this);
}

ClapTrap::~ClapTrap ()
{
	std::cout << "Destructor has been called" << std::endl;
}

void
ClapTrap::attack (const std::string &target)
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "ClapTrap " << name
					  << " can't attack: no energy or hit points left!"
					  << std::endl;
			return;
		}
	energy_points--;

	std::cout << "ClapTrap " << name << " attacks " << target << " causing "
			  << attack_data << " points of damage!" << std::endl;
}

void
ClapTrap::takeDamage (unsigned int amount)
{
	if (hit_points <= 0)
		{
			std::cout << "ClapTrap " << name << "is already dead!"
					  << std::endl;
			return;
		}

	hit_points -= amount;
	std::cout << "ClapTrap " << name << " took " << amount
			  << " points of damange!" << std::endl;
}

void
ClapTrap::beRepaired (unsigned int amount)
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "ClapTrap " << name
					  << " can't repair: no energy or hit points left!"
					  << std::endl;
			return;
		}
	energy_points--;

	hit_points += amount;
	std::cout << "ClapTrap " << name << " healed for " << amount
			  << " points of damange!" << std::endl;
}
