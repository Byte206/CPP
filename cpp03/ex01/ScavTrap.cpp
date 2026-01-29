#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Default_ScavTrap") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string const& name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other)
    : ClapTrap(other) {
    std::cout << "ScavTrap " << name << " copy constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << name << " assigned." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructed." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode."
              << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << std::endl;
    } else {
        std::cout << "ScavTrap " << name
                  << " has insufficient energy or hit points to attack."
                  << std::endl;
    }
}