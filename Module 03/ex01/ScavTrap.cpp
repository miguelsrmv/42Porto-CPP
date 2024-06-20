#include "ScavTrap.hpp"

ScavTrap::ScavTrap (const std::string &name)
{
	std::cout << "ScavTrap constructor has been called" << std::endl;

	this->name = "ScavTrap " + name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_data = 20;
}

ScavTrap::ScavTrap (const ScavTrap &copy) : ClapTrap (copy)
{
	std::cout << "ScavTrap Copy constructor has been called" << std::endl;

	*this = copy;
}

ScavTrap &
ScavTrap::operator= (const ScavTrap &copy)
{
	std::cout << "ScavTrap = assignment has been called" << std::endl;

	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_data = copy.attack_data;
	return (*this);
}

ScavTrap::~ScavTrap ()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}

void
ScavTrap::guardGate ()
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << name << " can't guard: no energy or hit points left!"
					  << std::endl;
			return;
		}
	std::cout << name << " is now in Gate Keeper Mode!" << std::endl;
}
