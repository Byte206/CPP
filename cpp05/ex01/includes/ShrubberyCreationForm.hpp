#include "Form.hpp"

class ShrubberyCreationForm : public Form {
   private:
    std::string target;

   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;
};