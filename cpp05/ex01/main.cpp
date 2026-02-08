#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main() {
    std::cout << "--- Test 1: Form Creation ---" << std::endl;
    try {
        std::string name = "Rental Contract";
        int signGrade = 50;
        int execGrade = 25;
        Form f1(name, signGrade, execGrade);
        std::cout << f1 << std::endl;
        
        // This should fail
        std::string name2 = "Impossible Form";
        int signGrade2 = 0;
        int execGrade2 = 151;
        Form f2(name2, signGrade2, execGrade2);
    } catch (std::exception &e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Bureaucrat signs successfully ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 10);
        std::string name = "Salary Raise";
        int signGrade = 20;
        int execGrade = 10;
        Form f3(name, signGrade, execGrade);
        
        std::cout << f3 << std::endl;
        boss.signForm(f3);
        std::cout << f3 << std::endl; // Should appear as signed
    } catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Bureaucrat grade too low ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::string name = "Vacation Leave";
        int signGrade = 1;
        int execGrade = 1;
        Form f4(name, signGrade, execGrade);
        
        std::cout << f4 << std::endl;
        intern.signForm(f4); // This will throw exception inside signForm
    } catch (std::exception &e) { //this catch is not needed because the exception 
        //is already handled inside signForm, but we can keep it to show that the exception does not propagate to main
        std::cout << "Caught in main: " << e.what() << std::endl;
    }

    return 0;
}
