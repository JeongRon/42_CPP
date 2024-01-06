#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  /* Block */
  ShrubberyCreationForm();
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);

 public:
  /* Lifecycle Functions */
  ShrubberyCreationForm(const std::string& name);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& form);

  /* Member Function */
  void execute(Bureaucrat const& executor) const;
  void action(std::string const& target) const;
};

#endif