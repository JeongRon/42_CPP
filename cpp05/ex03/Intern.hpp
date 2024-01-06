#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
 private:
  std::string formNameSearch[3];

 public:
  /* Lifecycle Functions */
  Intern();
  Intern& operator=(Intern const& other);
  Intern(Intern const& other);
  ~Intern();

  /* Member Function */
  AForm* makeShrubberyCreationForm(std::string& target);
  AForm* makeRobotomyRequestForm(std::string& target);
  AForm* makePresidentialPardonForm(std::string& target);

  AForm* makeForm(std::string formName, std::string target);
};

#endif