#include <string>
#include <iostream>
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap {
   protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

   public:
    ClapTrap();
    ClapTrap(std::string const& name);
    ClapTrap(ClapTrap const& other);
    ClapTrap& operator=(ClapTrap const& other);
    virtual ~ClapTrap();

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif