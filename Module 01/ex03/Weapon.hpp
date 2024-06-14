#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(std::string weapon_type);
	~Weapon();
	std::string get_type();
	void setType(std::string weapon_type);

private:
	std::string type;
};

#endif