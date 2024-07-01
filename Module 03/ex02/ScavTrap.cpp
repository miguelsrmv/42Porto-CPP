#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap ()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;

	std::cout << "ScavTrap default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap (const std::string &robot_name) : ClapTrap (robot_name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;

	std::cout << "ScravTrap " << this->name << " parametrized constructor has been called"
			  << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &copy) : ClapTrap (copy)
{
	std::cout << "ScavTrap copy constructor has been called" << std::endl;
	*this = copy;
}

ScavTrap &
ScavTrap::operator= (const ScavTrap &copy)
{
	std::cout << "ScavTrap = assignment has been called" << std::endl;

	if (this != &copy)
		{
			name = copy.name;
			hit_points = copy.hit_points;
			energy_points = copy.energy_points;
			attack_damage = copy.attack_damage;
		}
	return (*this);
}

ScavTrap::~ScavTrap ()
{
	std::cout << "ScravTrap " << name << " destructor has been called" << std::endl;
}

void
ScavTrap::guardGate ()
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "ScravTrap " << name << " can't guard: no energy or hit points left!"
					  << std::endl;
			return;
		}
	
	energy_points--;
	std::cout << "ScravTrap " << name << " entering guard gate mode!" << std::endl;
}

void
ScavTrap::attack (const std::string &target)
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "ScavTrap " << name << " can't attack: no energy or hit points left!"
					  << std::endl;
			return;
		}
	energy_points--;

	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage
			  << " points of damage!" << std::endl;
}
