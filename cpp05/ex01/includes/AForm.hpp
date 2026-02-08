#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
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

    AForm();
    AForm(std::string const& name, int gradeToSign, int gradeToExecute);
    AForm(AForm const& other);
    AForm& operator=(AForm const& other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const& b);

};

std::ostream& operator<<(std::ostream& os, AForm const& f);

#endif