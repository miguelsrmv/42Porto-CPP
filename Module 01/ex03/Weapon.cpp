#include "Weapon.hpp"

Weapon::Weapon (std::string weapon_type) : type (weapon_type) {}

Weapon::~Weapon () {}

std::string
Weapon::get_type ()
{
	return (type);
}

void
Weapon::setType (std::string weapon_type)
{
	type = weapon_type;
}
