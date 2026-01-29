#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << std::endl;
    } else {
        std::cout << "ClapTrap " << name
                  << " has insufficient energy or hit points to attack."
                  << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= amount) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage and is now destroyed!" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage, remaining hit points: " << hitPoints
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " is repaired by " << amount
                  << " points, new hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name
                  << " has insufficient energy or hit points to repair."
                  << std::endl;
    }
}