#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
   private:
    std::string name;  // Matching ClapTrap's attribute name

   public:
    DiamondTrap();
    DiamondTrap(std::string const& name);
    DiamondTrap(DiamondTrap const& other);
    DiamondTrap& operator=(DiamondTrap const& other);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();
};

#endif