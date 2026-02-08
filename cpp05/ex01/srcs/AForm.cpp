#include "AForm.hpp"

AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(AForm const& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(AForm const& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}  

AForm::~AForm() {}

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

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, AForm const& f) {
    os << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}
