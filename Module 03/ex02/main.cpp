#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap t1;
	FragTrap t2("Charizard");
	FragTrap t3(t2);

	std::cout << "\n-------- Testing t3(t2) --------\n" << std::endl;
	std::cout << t3;
	t3.attack("Pikachu");
	std::cout << t3;
	t3.takeDamage(9);
	std::cout << t3;
	t3.beRepaired(5);
	std::cout << t3;
	t3.highFivesGuys();
	std::cout << t3;
	t3.takeDamage(100);
	std::cout << t3;
	t3.beRepaired(50);
	std::cout << t3;

	std::cout << "\n-------- Testing t1 = t3 --------\n" << std::endl;
	t1 = t3;
	std::cout << t1 << std::endl;
}
