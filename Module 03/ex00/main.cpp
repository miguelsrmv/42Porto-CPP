#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap John("John", 10, 10, 10);

	John.attack("Jhonata");
	John.takeDamage(20);
	John.beRepaired(30);
}
