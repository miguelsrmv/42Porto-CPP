#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (void) : ScavTrap (), FragTrap ()
{
	std::cout << "DiamondTrap default constructor has been called"
			  << std::endl;

	name = "Unnamed DiamondTrap";
	this->ClapTrap::name = name + "_clap_name";
	this->hit_points = this->FragTrap::hit_points;
	this->energy_points = this->ScavTrap::energy_points;
	this->attack_data = this->FragTrap::attack_data;
}

DiamondTrap::DiamondTrap (const std::string &name) : ScavTrap (), FragTrap ()
{
	std::cout << "DiamondTrap parametized constructor has been called"
			  << std::endl;

	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hit_points = this->FragTrap::hit_points;
	this->energy_points = this->ScavTrap::energy_points;
	this->attack_data = this->FragTrap::attack_data;
}

DiamondTrap::DiamondTrap (const DiamondTrap &copy)
	: ClapTrap (), ScavTrap (), FragTrap ()
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
			this->attack_data = copy.attack_data;
		}
	return (*this);
}

DiamondTrap::~DiamondTrap () {}

void
DiamondTrap::whoAmI ()
{
	std::cout << "My DiamondTrap name is " << name
			  << " but my ClapTrap name is " << this->ClapTrap::name
			  << std::endl;
}