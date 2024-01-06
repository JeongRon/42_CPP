#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  /* Block */
  PresidentialPardonForm();
  PresidentialPardonForm& operator=(const PresidentialPardonForm& form);

 public:
  /* Lifecycle Functions */
  PresidentialPardonForm(const std::string& name);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& form);

  /* Member Function */
  void execute(Bureaucrat const& executor) const;
  void action(const std::string& target) const;
};

#endif