#include "ScavTrap.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

ScavTrap::ScavTrap()
    : ClapTrap("Default_ScavTrap") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << RED << "ScavTrap " << name << " constructed." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string const& name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << RED << "ScavTrap " << name << " constructed." << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other)
    : ClapTrap(other) {
    std::cout << RED << "ScavTrap " << name << " copy constructed." << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& other) {
    ClapTrap::operator=(other);
    std::cout << RED << "ScavTrap " << name << " assigned." << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap " << name << " destructed." << RESET << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << RED << "ScavTrap " << name << " is now in Gate Keeper mode."
              << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        std::cout << RED << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << RESET << std::endl;
    } else {
        std::cout << RED << "ScavTrap " << name
                  << " has insufficient energy or hit points to attack."
                  << RESET << std::endl;
    }
}