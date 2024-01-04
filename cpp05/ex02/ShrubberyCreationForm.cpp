#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& form) {
  (void)form;
  return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
    : AForm(form) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {}
