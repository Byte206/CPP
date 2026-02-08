#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
   private:
    const std::string target;

   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const& target);
    RobotomyRequestForm(RobotomyRequestForm const& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
    virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};

#endif
