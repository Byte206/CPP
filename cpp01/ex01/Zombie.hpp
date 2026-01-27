#include <string>
#include <iostream>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce();
    void setName(std::string name);

private:
    std::string name;
};