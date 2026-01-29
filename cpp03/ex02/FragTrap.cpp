#include "FragTrap.hpp"

#define BLUE "\033[34m"
#define RESET "\033[0m"

FragTrap::FragTrap()
    : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << BLUE << "FragTrap " << name << " constructed via default." << RESET << std::endl;
}

FragTrap::FragTrap(std::string const& name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << BLUE << "FragTrap " << name << " constructed." << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const& other)
    : ClapTrap(other) {
    std::cout << BLUE << "FragTrap " << name << " copy constructed." << RESET << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& other) {
    ClapTrap::operator=(other);
    std::cout << BLUE << "FragTrap " << name << " assigned." << RESET << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << BLUE << "FragTrap " << name << " destructed." << RESET << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        std::cout << BLUE << "FragTrap " << name << " fiercely attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << RESET << std::endl;
    } else {
        std::cout << BLUE << "FragTrap " << name
                  << " has insufficient energy or hit points to attack."
                  << RESET << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << BLUE << "FragTrap " << name << " is requesting a high five! ✋"
              << RESET << std::endl;
}

