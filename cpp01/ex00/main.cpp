#include <string>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    //heap zombie
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    //stack zombie
    randomChump("StackZombie");

    return 0;
}