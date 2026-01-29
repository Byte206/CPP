#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing ClapTrap Construction ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("a bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- Testing ScavTrap Construction (Chain) ---" << std::endl;
    ScavTrap scav("Scavvy");
    
    std::cout << "\n--- Testing ScavTrap Actions ---" << std::endl;
    scav.attack("a monster"); // Uses ScavTrap's special attack message
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();         // ScavTrap's special ability

    std::cout << "\n--- Testing ScavTrap Copy and Assignment ---" << std::endl;
    ScavTrap scavCopy(scav);
    ScavTrap scavAssigned("Temporary");
    scavAssigned = scav;
    scavAssigned.guardGate();

    std::cout << "\n--- Testing Polymorphism ---" << std::endl;
    ClapTrap* poly = new ScavTrap("PolyScav");
    poly->attack("someone"); // Should call ScavTrap::attack if virtual
    delete poly;             // Should call both destructors because virtual

    std::cout << "\n--- Destruction starts here ---" << std::endl;
    return 0;
}
