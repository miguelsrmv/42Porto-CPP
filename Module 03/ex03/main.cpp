#include "DiamondTrap.hpp"

void printHeader(std::string str) {
    std::cout << "\n" << str << "\n" << std::endl;
}


int main() {
    // Create a DiamondTrap object
    printHeader("Creating a DiamondTrap");
    DiamondTrap diamond("Diamond");

    // Test inherited FragTrap functionalities
    printHeader("Printing DiamondTrap attributes");

    // Test DiamondTrap specific functionality
    printHeader("DiamondTrap requesting a high five");
    diamond.highFivesGuys();

    // Test ScavTrap specific functionality
    printHeader("DiamondTrap guarding the gate");
    diamond.guardGate();

    // Test DiamondTrap specific functionality
    printHeader("DiamondTrap introspecting");
    diamond.whoAmI();

    printHeader("End of Program (Destructors will be called automatically)");

    return 0;
}