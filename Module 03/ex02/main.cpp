#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap CTrap("A");

	CTrap.attack("enemy");
	CTrap.takeDamage(0);
	CTrap.takeDamage(5);
	CTrap.beRepaired(10);

	ClapTrap Copy_CTrap(CTrap);

	Copy_CTrap.takeDamage(14);
	Copy_CTrap.attack("enemy");
	Copy_CTrap.beRepaired(0);
	Copy_CTrap.takeDamage(1);
	Copy_CTrap.attack("enemy");
	Copy_CTrap.beRepaired(10);
	Copy_CTrap.takeDamage(0);

	std::cout << std::endl
			  << std::endl
			  << std::endl;

	/////////////////////////////////////////////////////////

	ScavTrap Strap("B");

	Strap.attack("another enemy");
	Strap.guardGate();

	std::cout << std::endl
			  << std::endl
			  << std::endl;

	/////////////////////////////////////////////////////////

	FragTrap Ftrap("C");

	Ftrap.attack("another enemy");
	Ftrap.highFivesGuys();
}
