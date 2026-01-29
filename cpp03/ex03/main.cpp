#include "includes/DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- Initializing DiamondTrap ---" << std::endl;
    DiamondTrap monster("Sparky");

    std::cout << "\n--- Testing whoAmI ---" << std::endl;
    monster.whoAmI();

    std::cout << "\n--- Testing inherited attributes (HP:100, EP:50, AD:30) ---" << std::endl;
    monster.attack("a target"); // Should use ScavTrap attack
    monster.takeDamage(20);
    monster.beRepaired(10);

    std::cout << "\n--- Testing special functions ---" << std::endl;
    monster.guardGate();    // From ScavTrap
    monster.highFivesGuys(); // From FragTrap

    std::cout << "\n--- Testing Copy ---" << std::endl;
    {
        DiamondTrap copy(monster);
        copy.whoAmI();
    }

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}
