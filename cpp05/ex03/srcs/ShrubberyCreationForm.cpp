#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm default constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm for " << target << " constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm for " << target << " copy constructed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
    (void)other;
    std::cout << "ShrubberyCreationForm assigned." << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm for " << target << " destructed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    this->checkExecution(executor);

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "      /\\      " << std::endl;
        outfile << "     /\\*\\     " << std::endl;
        outfile << "    /\\O\\*\\    " << std::endl;
        outfile << "   /*/\\/\\/\\   " << std::endl;
        outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
        outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile << std::endl;
        outfile << "      /\\      " << std::endl;
        outfile << "     /  \\     " << std::endl;
        outfile << "    /    \\    " << std::endl;
        outfile << "   /      \\   " << std::endl;
        outfile << "  /________\\  " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile.close();
    } else {
        std::cerr << "Error: Could not open file for writing shrubbery." << std::endl;
    }
}
