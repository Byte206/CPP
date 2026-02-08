#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
   private:
    const std::string target;

   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;
};

#endif
