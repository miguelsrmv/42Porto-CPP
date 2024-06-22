#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor has been called" << std::endl;
    name = "Unnamed ScavTrap";
    hit_points = 100;
    energy_points = 50;
    attack_data = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap()
{
    std::cout << "ScavTrap parametrized constructor has been called" << std::endl;
    this->name = "ScavTrap " + name;
    hit_points = 100;
    energy_points = 50;
    attack_data = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor has been called" << std::endl;
    *this = copy;
}

ScavTrap &
ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap = assignment has been called" << std::endl;

    if (this != &copy)
    {
        name = copy.name;
        hit_points = copy.hit_points;
        energy_points = copy.energy_points;
        attack_data = copy.attack_data;
    }
    return (*this);
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor has been called" << std::endl;
}

void ScavTrap::guardGate()
{
    if (!energy_points || hit_points <= 0)
    {
        std::cout << name << " can't guard: no energy or hit points left!"
                  << std::endl;
        return;
    }
    std::cout << name << " entering guard gate mode!"
              << std::endl;
}
