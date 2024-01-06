#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  /* Block */
  RobotomyRequestForm();
  RobotomyRequestForm& operator=(const RobotomyRequestForm& form);

 public:
  /* Lifecycle Functions */
  RobotomyRequestForm(const std::string& name);
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& form);

  /* Member Function */
  void execute(Bureaucrat const& executor) const;
  void action() const;

  /* Exception Class-Function */
  class RobotFailedException : public std::exception {
    const char* what() const throw();
  };
};

#endif