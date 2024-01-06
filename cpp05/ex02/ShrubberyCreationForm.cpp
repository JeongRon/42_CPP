#include "ShrubberyCreationForm.hpp"

#include "Bureaucrat.hpp"

/* Block */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("dafault", 145, 137) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& form) {
  (void)form;
  return (*this);
}

/* Lifecycle Functions */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
    : AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
    : AForm(form) {}

/* Member Function */
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  // sign check
  if (this->getSignFlag() == false) throw AForm::NotSignedException();
  // execute check
  if (this->getExecuteGrade() < executor.getGrade())
    throw AForm::GradeTooHighException();
  // ShrubberyCreationForm action
  ShrubberyCreationForm::action(executor.getName());
}

void ShrubberyCreationForm::action(std::string const& target) const {
  std::string file_name(target + "_shrubbery");
  std::ofstream new_file(file_name.c_str());
  new_file << "          &&& &&  & &&\n"
              "      && &\\/&\\|& ()|/ @, &&\n"
              "      &\\/(/&/&||/& /_/)_&/_&\n"
              "   &() &\\/&|()|/&\\/ '%\" & ()\n"
              "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
              "&&   && & &| &| /& & % ()& /&&\n"
              " ()&_---()&\\&\\|&&-&&--%---()~\n"
              "     &&     \\|||\n"
              "             |||\n"
              "             |||\n"
              "             |||\n"
              "       , -=-~  .-^- _\"\n";
  new_file.close();
}