#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (void) : ScavTrap (), FragTrap ()
{
	std::cout << "DiamondTrap default constructor has been called"
			  << std::endl;

	this->name = "Unnamed DiamondTrap";
	this->ClapTrap::name = name + "_clap_name";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap (const std::string &robot_name) : ScavTrap (robot_name), FragTrap (robot_name)
{
	std::cout << "DiamondTrap parametized constructor has been called"
			  << std::endl;

	this->name = robot_name;
	this->ClapTrap::name = robot_name + "_clap_name";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap (const DiamondTrap &copy)
	: ClapTrap (copy), ScavTrap (copy), FragTrap (copy)
{

	std::cout << "DiamondTrap copy constructor has been called" << std::endl;

	*this = copy;
}

DiamondTrap &
DiamondTrap::operator= (const DiamondTrap &copy)
{
	std::cout << "DiamondTrap = assignment has been called" << std::endl;

	if (this != &copy)
		{
			this->name = copy.name;
			this->hit_points = copy.hit_points;
			this->energy_points = copy.energy_points;
			this->attack_damage = copy.attack_damage;
			this->ClapTrap::name = copy.ClapTrap::name;
		}
	return (*this);
}

DiamondTrap::~DiamondTrap ()
{
	std::cout << "DiamondTrap " << name << " destructor has been called"
			  << std::endl;
}

void
DiamondTrap::whoAmI ()
{
	std::cout << "My DiamondTrap name is " << name
			  << " but my ClapTrap name is " << this->ClapTrap::name
			  << std::endl;
}
