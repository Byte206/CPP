#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    std::cout << "Bureaucrat " << name << " constructed via default." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat " << name << " constructed with grade " << grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat " << name << " copy constructed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    std::cout << "Bureaucrat " << name << " assigned." << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << name << " destructed." << std::endl;
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    --grade;
    std::cout << "Bureaucrat " << name << " incremented to grade " << grade << "." << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    ++grade;
    std::cout << "Bureaucrat " << name << " decremented to grade " << grade << "." << std::endl;
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
