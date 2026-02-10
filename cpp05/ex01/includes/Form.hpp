#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
   private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Form();
    Form(std::string const& name, int gradeToSign, int gradeToExecute);
    Form(Form const& other);
    Form& operator=(Form const& other);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const& b);

};

std::ostream& operator<<(std::ostream& os, Form const& f);

#endif
