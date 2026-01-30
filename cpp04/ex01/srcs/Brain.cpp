#include "Brain.hpp"

// Color rosa claro #F56BFA
#define PINK "\033[38;2;245;107;250m"
#define RESET "\033[0m"

Brain::Brain() {
    std::cout << PINK << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
    *this = other;
    std::cout << PINK << "Brain copy constructor called" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << PINK << "Brain destructor called" << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return "";
}
