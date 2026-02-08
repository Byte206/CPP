#include "Form.hpp"

class RobotomyRequestForm : public Form {
   private:
    std::string target;

   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const& target);
    RobotomyRequestForm(RobotomyRequestForm const& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};