#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name, int hit_points, int energy_points, unsigned int attack_data);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator= (const ClapTrap &copy);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
	private:
		std::string name;
		int hit_points;
		int energy_points;
		unsigned int attack_data;
};

#endif
