#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm default constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm for " << target << " constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
    : AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm for " << target << " copy constructed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
    (void)other;
    std::cout << "RobotomyRequestForm assigned." << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm for " << target << " destructed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    this->checkExecution(executor);

    std::cout << "* Whirrr... Drilling noises... *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy on " << target << " failed." << std::endl;
    }
}
