#include "includes/Bureaucrat.hpp"

int main() {
    // Test 1: Valid creation and operator<< usage
    try {
        Bureaucrat ok("Alice", 75);
        std::cout << ok << std::endl;

        ok.incrementGrade();
        std::cout << ok << std::endl;

        ok.decrementGrade();
        std::cout << ok << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught in Test 1: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Constructor with grade too high ---" << std::endl;
    try {
        Bureaucrat high("High", 0); // should throw GradeTooHighException
        std::cout << high << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Constructor with grade too low ---" << std::endl;
    try {
        Bureaucrat low("Low", 151); // should throw GradeTooLowException
        std::cout << low << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: incrementGrade out of range ---" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade(); // should throw GradeTooHighException
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: decrementGrade out of range ---" << std::endl;
    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade(); // should throw GradeTooLowException
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
