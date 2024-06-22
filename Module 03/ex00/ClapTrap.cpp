#include "ClapTrap.hpp"

ClapTrap::ClapTrap ()
	: name ("Unnamed ClapTrap"), hit_points (10), energy_points (10),
	  attack_data (0)
{
	std::cout << "ClapTrap default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap (const std::string &name)
	: name (name), hit_points (10), energy_points (10), attack_data (0)
{
	std::cout << "ClapTrap parametrized constructor has been called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;

	*this = copy;
}

ClapTrap &
ClapTrap::operator= (const ClapTrap &copy)
{
	std::cout << "ClapTrap = assignment has been called" << std::endl;

	if (this != &copy)
		{
			this->name = copy.name;
			this->hit_points = copy.hit_points;
			this->attack_data = copy.attack_data;
			this->energy_points = copy.energy_points;
		}
	return (*this);
}

ClapTrap::~ClapTrap ()
{
	std::cout << "Claptrap " << name << " destructor has been called"
			  << std::endl;
}

void
ClapTrap::attack (const std::string &target)
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "ClapTrap " << name << " can't attack: no energy or hit points left!"
					  << std::endl;
			return;
		}
	energy_points--;

	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_data
			  << " points of damage!" << std::endl;
}

void
ClapTrap::takeDamage (unsigned int amount)
{
	if (hit_points <= 0)
		{
			std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
			return;
		}

	hit_points -= amount;
	std::cout << "ClapTrap " << name << " took " << amount << " points of damange!"
			  << std::endl;
}

void
ClapTrap::beRepaired (unsigned int amount)
{
	if (!energy_points || hit_points <= 0)
		{
			std::cout << "ClapTrap " << name << " can't repair: no energy or hit points left!"
					  << std::endl;
			return;
		}
	energy_points--;

	hit_points += amount;
	std::cout << "ClapTrap " << name << " healed for " << amount << " points of damange!"
			  << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

int ClapTrap::getHealth(void) const
{
	return (this->hit_points);
}

int ClapTrap::getEnergy(void) const
{
	return (this->energy_points);
}

int ClapTrap::getDamage(void) const
{
	return (this->attack_data);
}

std::ostream &operator<< (std::ostream &out, const ClapTrap &Trap)
{
	out << "Claptrap name: " << Trap.getName() << std::endl ;
	out << "Health: " << Trap.getHealth() << std::endl ;
	out << "Energy: " << Trap.getEnergy() << std::endl ;
	out << "Damage: " << Trap.getDamage() << std::endl ;
	out << std::endl ;

	return out;
}
