#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   private:
    const std::string target;

   public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const& executor) const;
};

#endif
