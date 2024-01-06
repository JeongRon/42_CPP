#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* Lifecycle Functions */
Intern::Intern() {
  formNameSearch[0] = "shrubbery creation";
  formNameSearch[1] = "robotomy request";
  formNameSearch[2] = "presidential pardon";
}

Intern& Intern::operator=(Intern const& other) {
  (void)other;
  return (*this);
}

Intern::Intern(Intern const& other) { *this = other; }

Intern::~Intern() {}

/* Member Function */
AForm* Intern::makeShrubberyCreationForm(std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(std::string& target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
  AForm* (Intern::*createForm[3])(std::string& target) = {
      &Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
      &Intern::makePresidentialPardonForm};

  for (int i = 0; i < 3; i++) {
    if (formName == formNameSearch[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*createForm[i])(target);
    }
  }
  std::cout << "Intern not found Form" << std::endl;
  return NULL;
}
