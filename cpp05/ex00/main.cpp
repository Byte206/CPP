#include "includes/Bureaucrat.hpp"

int main() {
    // Test 1: creación válida y uso de operador <<
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

    std::cout << "\n--- Test 2: constructor con grade demasiado alto ---" << std::endl;
    try {
        Bureaucrat high("High", 0); // debería lanzar GradeTooHighException
        std::cout << high << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: constructor con grade demasiado bajo ---" << std::endl;
    try {
        Bureaucrat low("Low", 151); // debería lanzar GradeTooLowException
        std::cout << low << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: incrementGrade fuera de rango ---" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade(); // debería lanzar GradeTooHighException
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: decrementGrade fuera de rango ---" << std::endl;
    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade(); // debería lanzar GradeTooLowException
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
