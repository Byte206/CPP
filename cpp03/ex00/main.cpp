#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing ClapTrap constructors ---" << std::endl;
    ClapTrap clappy("Clappy");
    ClapTrap clappyCopy(clappy);
    ClapTrap clappyAssigned("Temp");
    clappyAssigned = clappy;

    std::cout << "\n--- Testing ClapTrap actions ---" << std::endl;
    clappy.attack("Target");
    clappy.takeDamage(5);
    clappy.beRepaired(3);
    clappy.takeDamage(10);
    clappy.attack("Target"); // Should fail (no hit points)
    clappy.beRepaired(5);    // Should fail (no hit points)

    std::cout << "\n--- Testing energy exhaustion ---" << std::endl;
    ClapTrap energetic("Energetic");
    for (int i = 0; i < 11; ++i) {
        std::cout << "Action " << i + 1 << ": ";
        energetic.attack("someone");
    }
    energetic.beRepaired(10); // Should fail (no energy)

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}
