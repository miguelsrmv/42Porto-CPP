#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  public:
	HumanA (std::string human_name, Weapon &type);
	~HumanA ();
	void attack ();

  private:
	std::string name;
	Weapon &weapon;
};

#endif