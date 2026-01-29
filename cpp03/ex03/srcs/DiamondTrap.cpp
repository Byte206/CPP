#include "../includes/DiamondTrap.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name("Default") {
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << GREEN << "DiamondTrap " << this->name << " default constructed." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    
    this->hitPoints = 100;    // FragTrap
    this->energyPoints = 50;  // ScavTrap
    this->attackDamage = 30;  // FragTrap
    
    std::cout << GREEN << "DiamondTrap " << this->name << " constructed." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    *this = other;
    std::cout << GREEN << "DiamondTrap " << this->name << " copy constructed." << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other) {
    if (this != &other) {
        this->name = other.name;
        ClapTrap::name = other.ClapTrap::name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << GREEN << "DiamondTrap " << this->name << " assigned." << RESET << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << GREEN << "DiamondTrap " << this->name << " destructed." << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << GREEN << "I am Diamond: " << this->name 
              << " and my ClapTrap name is: " << ClapTrap::name << RESET << std::endl;
}
