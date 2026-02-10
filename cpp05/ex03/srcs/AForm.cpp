#include "../includes/AForm.hpp"
#include <exception>
#include <iostream>

AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm " << name << " default constructed." << std::endl;
}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
    std::cout << "AForm " << name << " constructed." << std::endl;
}

AForm::AForm(AForm const& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "AForm " << name << " copy constructed." << std::endl;
}

AForm& AForm::operator=(AForm const& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    std::cout << "AForm " << name << " assigned." << std::endl;
    return *this;
}  

AForm::~AForm() {
    std::cout << "AForm " << name << " destructed." << std::endl;
}

std::string AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat const& b) {
    if (b.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

void AForm::checkExecution(Bureaucrat const& executor) const {
    if (!isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, AForm const& f) {
    os << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}
