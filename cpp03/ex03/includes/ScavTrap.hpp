#include "ClapTrap.hpp"
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap : virtual public ClapTrap {
   public:
    ScavTrap();
    ScavTrap(std::string const& name);
    ScavTrap(ScavTrap const& other);
    ScavTrap& operator=(ScavTrap const& other);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
};

#endif