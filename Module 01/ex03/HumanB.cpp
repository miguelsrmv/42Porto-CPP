#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB (std::string human_name) : name (human_name) { weapon = NULL; }

HumanB::~HumanB () {}

void
HumanB::setWeapon (Weapon &type)
{
	weapon = &type;
}

void
HumanB::attack () const
{
	std::cout << name << " attacks with his ";

	if (weapon != NULL)
		std::cout << weapon->get_type () << std::endl;
	else
		std::cout << "bare hands" << std::endl;
}
