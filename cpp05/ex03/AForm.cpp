#include "AForm.hpp"

#include "Bureaucrat.hpp"

/* Block */
AForm::AForm()
    : name("default"), signFlag(false), signGrade(50), executeGrade(50) {}

AForm& AForm::operator=(const AForm& other) {
  (void)other;
  return (*this);
}

/* Lifecycle Functions */
AForm::AForm(const std::string& name, const int& signGrade,
             const int& executeGrade)
    : name(name),
      signFlag(false),
      signGrade(signGrade),
      executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1)
    throw AForm::GradeTooHighException();
  else if (150 < signGrade || 150 < executeGrade)
    throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
    : name(other.name),
      signFlag(other.signFlag),
      signGrade(other.signGrade),
      executeGrade(other.executeGrade) {}

/* Getter */
const std::string& AForm::getName() const { return (name); }
const bool& AForm::getSignFlag() const { return (signFlag); }
const int& AForm::getSignGrade() const { return (signGrade); }
const int& AForm::getExecuteGrade() const { return (executeGrade); }

/* Member Function */
void AForm::beSigned(Bureaucrat& bureaucrat) {
  if (this->getSignGrade() < bureaucrat.getGrade()) {
    throw AForm::GradeTooLowException();
  }
  this->signFlag = true;
}

/* Exception Class-Function */
const char* AForm::GradeTooHighException::what() const throw() {
  return "Form: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Form: Grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
  return "Form: Not Signed";
}

/* Insertion operator */
std::ostream& operator<<(std::ostream& output, const AForm& form) {
  output << "name: " << form.getName() << " / "
         << "signed: " << (form.getSignFlag() ? "true" : "false") << " / "
         << "singGrade: " << form.getSignGrade() << " / "
         << "executeGrade: " << form.getExecuteGrade();
  return (output);
}