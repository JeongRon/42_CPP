#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"

/* Block */
PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& form) {
  (void)form;
  return (*this);
}

/* Lifecycle Functions */
PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
    : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& form)
    : AForm(form) {}

/* Member Function */
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  // sign check
  if (this->getSignFlag() == false) throw AForm::NotSignedException();
  // execute check
  if (this->getExecuteGrade() < executor.getGrade())
    throw AForm::GradeTooHighException();
  // PresidentialPardonForm action
  PresidentialPardonForm::action(executor.getName());
}

void PresidentialPardonForm::action(std::string const& target) const {
  std::cout << target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
