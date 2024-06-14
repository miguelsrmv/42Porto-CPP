#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie(const std::string &name);
	Zombie(void);
	~Zombie();

	void announce(void) const;
	void set_name(const std::string &name);

private:
	std::string zombie_name;
};

Zombie *zombieHorde(int N, std::string name);

#endif