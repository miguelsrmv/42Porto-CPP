#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string human_name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon &type);

private:
	std::string name;
	Weapon *weapon;
};

#endif