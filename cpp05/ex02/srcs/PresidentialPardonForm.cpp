#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("default") {
    std::cout << "PresidentialPardonForm default constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("Presidential Pardon", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm for " << target << " constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
    : AForm(other), target(other.target) {
    std::cout << "PresidentialPardonForm for " << target << " copy constructed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
    (void)other;
    std::cout << "PresidentialPardonForm assigned." << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm for " << target << " destructed." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    this->checkExecution(executor);

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
