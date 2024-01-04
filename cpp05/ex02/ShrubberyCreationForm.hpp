#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);

 public:
  ShrubberyCreationForm(const std::string& target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& form);

  void execute(Bureaucrat const& executor) const;
};

#endif