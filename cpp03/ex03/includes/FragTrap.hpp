#include "ClapTrap.hpp"
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


class FragTrap : virtual public ClapTrap {
   public:
    FragTrap();
    FragTrap(std::string const& name);
    FragTrap(FragTrap const& other);
    FragTrap& operator=(FragTrap const& other);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys();
};

#endif