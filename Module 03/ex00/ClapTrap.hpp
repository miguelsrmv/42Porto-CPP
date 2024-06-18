#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
		ClapTrap(int hit_points, int energy_points, unsigned int attack_data);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator= (const ClapTrap &copy);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
	private:
		int hit_points;
		int energy_points;
		unsigned int attack_data;
};

#endif