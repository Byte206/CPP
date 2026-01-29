#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("a training dummy");

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("a bandit");
    scav.guardGate();

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("a giant robot");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();

    std::cout << "\n--- Testing FragTrap Copy & Assignment ---" << std::endl;
    FragTrap fragCopy(frag);
    FragTrap fragAssigned;
    fragAssigned = frag;
    fragAssigned.highFivesGuys();

    std::cout << "\n--- Testing Deep Inheritance Order ---" << std::endl;
    // This will show: ClapTrap constructor -> FragTrap constructor
    FragTrap* deep = new FragTrap("Deppy");
    delete deep; // This will show: FragTrap destructor -> ClapTrap destructor

    std::cout << "\n--- Destruction of local objects ---" << std::endl;
    return 0;
}
