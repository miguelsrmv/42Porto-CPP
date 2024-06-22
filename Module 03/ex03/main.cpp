#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap t1;
	DiamondTrap t2("Charizard");
	DiamondTrap t3(t2);

	std::cout << "\n-------- Testing t3(t2) --------\n" << std::endl;
	std::cout << t3;
	t3.attack("Pikachu");
	std::cout << t3;
	t3.takeDamage(9);
	std::cout << t3;
	t3.beRepaired(5);
	std::cout << t3;
	t3.guardGate();
	std::cout << t3;
	t3.highFivesGuys();
	std::cout << t3;
	t3.whoAmI();
	std::cout << t3;
	t3.takeDamage(100);
	std::cout << t3;
	t3.beRepaired(50);
	std::cout << t3;

	std::cout << "\n-------- Testing t1 = t3 --------\n" << std::endl;
	t1 = t3;
	std::cout << t1;
	t3.whoAmI();
	std::cout << t3 << std::endl;
}