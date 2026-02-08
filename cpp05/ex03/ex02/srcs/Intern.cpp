#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& other) {
    *this = other;
}

Intern& Intern::operator=(Intern const& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(std::string const& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(std::string const& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target) const {
    std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*creators[])(std::string const&) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create form '" << formName << "' (unknown name)." << std::endl;
    return NULL;
}
