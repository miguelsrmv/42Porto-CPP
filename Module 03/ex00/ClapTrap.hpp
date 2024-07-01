#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
  public:
	ClapTrap ();
	ClapTrap (const std::string &robot_name);
	ClapTrap (const ClapTrap &copy);
	ClapTrap &operator= (const ClapTrap &copy);
	~ClapTrap ();

	void attack (const std::string &target);
	void takeDamage (unsigned int amount);
	void beRepaired (unsigned int amount);

	std::string getName (void) const;
	int getHealth (void) const;
	int getEnergy (void) const;
	int getDamage (void) const;

  private:
	std::string name;
	int hit_points;
	int energy_points;
	unsigned int attack_damage;
};

std::ostream &operator<< (std::ostream &out, const ClapTrap &Claptrap);

#endif
