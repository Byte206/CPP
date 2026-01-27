#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}