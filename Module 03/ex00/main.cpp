#include "ClapTrap.hpp"

int
main (void)
{
	ClapTrap Charizard ("Charizard");

	Charizard.attack ("Venusaur");
	Charizard.takeDamage (0);
	Charizard.takeDamage (5);
	Charizard.beRepaired (10);

	ClapTrap Shiny_Charizard (Charizard);

	Shiny_Charizard.takeDamage (14);
	Shiny_Charizard.attack ("Venusaur");
	Shiny_Charizard.beRepaired (0);
	Shiny_Charizard.takeDamage (1);
	Shiny_Charizard.attack ("Venusaur");
	Shiny_Charizard.beRepaired (10);
	Shiny_Charizard.takeDamage (0);
}
