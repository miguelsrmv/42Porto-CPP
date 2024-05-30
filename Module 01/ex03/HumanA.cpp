#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA (std::string human_name, Weapon& type) : name(human_name), weapon(type)
{
}

HumanA::~HumanA () {}

void
HumanA::attack ()
{
	std::cout << name << " attacks with their " << weapon.get_type ()
			  << std::endl;
}

