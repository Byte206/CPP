#include "includes/Bureaucrat.hpp"
#include "includes/Intern.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(0));

    std::cout << "========== BUREAUCRAT AND FORM TESTS ==========" << std::endl;

    try {
        Bureaucrat president("Zaphod", 1);
        Bureaucrat assistant("Arthur", 40);
        Bureaucrat intern("Marvin", 150);

        ShrubberyCreationForm shrub("Garden"); //level 145 sign, 137 exec
        RobotomyRequestForm robot("Target1"); //level 72 sign, 45 exec
        PresidentialPardonForm pardon("Cheadle"); //level 25 sign, 5 exec

        std::cout << "\n--- SHRUBBERY CREATION FORM (145 sign, 137 exec) ---" << std::endl;
        std::cout << shrub << std::endl;
        intern.executeForm(shrub);    // Error: Not signed
        intern.signForm(shrub);       // Error: Grade too low
        assistant.signForm(shrub);    // Success
        intern.executeForm(shrub);    // Error: Grade too low
        assistant.executeForm(shrub); // Success: Creates Garden_shrubbery

        std::cout << "\n--- ROBOTOMY REQUEST FORM (72 sign, 45 exec) ---" << std::endl;
        std::cout << robot << std::endl;
        assistant.signForm(robot);    // Success
        intern.executeForm(robot);    // Error: Grade too low
        assistant.executeForm(robot); // Success (50% chance success/fail message)
        president.executeForm(robot); // Success (Another chance)

        std::cout << "\n--- PRESIDENTIAL PARDON FORM (25 sign, 5 exec) ---" << std::endl;
        std::cout << pardon << std::endl;
        assistant.signForm(pardon);   // Error: Grade too low (Arthur is 40)
        president.signForm(pardon);   // Success
        assistant.executeForm(pardon);// Error: Grade too low
        president.executeForm(pardon); // Success

        std::cout << "\n--- DESTRUCTOR REQUISITES ---" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    try {
        Intern someRandomIntern;
        Bureaucrat boss("Zaphod", 1);
        AForm* rrf;

        std::cout << "--- Test 1: Robotomy ---" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }

        std::cout << "\n--- Test 2: Shrubbery ---" << std::endl;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }

        std::cout << "\n--- Test 3: Presidential Pardon ---" << std::endl;
        rrf = someRandomIntern.makeForm("presidential pardon", "Marvin");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }

        std::cout << "\n--- Test 4: Unknown Form ---" << std::endl;
        rrf = someRandomIntern.makeForm("coffee request", "Kitchen");
        if (rrf) {
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    return 0;
}
