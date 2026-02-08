#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
   private:
    const std::string name;
    int grade;

   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &f);
    void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif