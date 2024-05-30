#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB (std::string human_name)
	: name (human_name)
{
	weapon = NULL;
}

HumanB::~HumanB () {}

void
HumanB::setWeapon (Weapon& type)
{
	weapon = &type;
}

void
HumanB::attack ()
{
	std::cout << name << " attacks with their " << weapon->get_type ()
			  << std::endl;
}