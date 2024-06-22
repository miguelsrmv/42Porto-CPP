#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Unnamed ClapTrap"), hit_points(10), energy_points(10),
	  attack_data(0)
{
	std::cout << "ClapTrap default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name("ClapTrap " + name), hit_points(10), energy_points(10),
	  attack_data(0)
{
	std::cout << this->name << " parametrized constructor has been called"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
}

ClapTrap &
ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap = assignment has been called" << std::endl;

	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->attack_data = copy.attack_data;
	this->energy_points = copy.energy_points;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!energy_points || hit_points <= 0)
	{
		std::cout << name << " can't attack: no energy or hit points left!"
				  << std::endl;
		return;
	}
	energy_points--;

	std::cout << name << " attacks " << target << " causing " << attack_data
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << name << " is already dead!" << std::endl;
		return;
	}

	hit_points -= amount;
	std::cout << name << " took " << amount << " points of damange!"
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy_points || hit_points <= 0)
	{
		std::cout << name << " can't repair: no energy or hit points left!"
				  << std::endl;
		return;
	}
	energy_points--;

	hit_points += amount;
	std::cout << name << " healed for " << amount << " points of damange!"
			  << std::endl;
}
