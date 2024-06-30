#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap ()
{
	hit_points = 100;
	energy_points = 100;
	attack_data = 30;

	std::cout << "FragTrap default constructor has been called" << std::endl;
}

FragTrap::FragTrap (const std::string &name) : ClapTrap (name)
{
	hit_points = 100;
	energy_points = 100;
	attack_data = 30;

	std::cout << "FragTrap " << this->name
			  << " parametrized constructor has been called" << std::endl;
}

FragTrap::FragTrap (const FragTrap &copy) : ClapTrap ()
{
	*this = copy;

	std::cout << "FragTrap copy constructor has been called" << std::endl;
}

FragTrap &
FragTrap::operator= (const FragTrap &copy)
{
	std::cout << "FragTrap = assignment has been called" << std::endl;

	if (this != &copy)
		{
			name = copy.name;
			hit_points = copy.hit_points;
			energy_points = copy.energy_points;
			attack_data = copy.energy_points;
		}
	return (*this);
}

FragTrap::~FragTrap ()
{
	std::cout << "FragTrap " << name << " destructor has been called"
			  << std::endl;
}

void
FragTrap::highFivesGuys ()
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "FragTrap " << name
					  << " can't high five: no energy or hit points left!"
					  << std::endl;
			return;
		}

	energy_points--;
	std::cout << "FragTrap " << name << " high fives everyone in the room!"
			  << std::endl;
}
