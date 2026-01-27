#include <string>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif
