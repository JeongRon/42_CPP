#include "Form.hpp"

#include "Bureaucrat.hpp"

/* Block */
Form::Form()
    : name("default"), signFlag(false), signGrade(50), executeGrade(50) {}

Form& Form::operator=(const Form& other) {
  (void)other;
  return (*this);
}

/* Lifecycle Functions */
Form::Form(const std::string name, const int signGrade, const int executeGrade)
    : name(name),
      signFlag(false),
      signGrade(signGrade),
      executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1)
    throw Form::GradeTooHighException();
  else if (150 < signGrade || 150 < executeGrade)
    throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
    : name(other.name),
      signFlag(other.signFlag),
      signGrade(other.signGrade),
      executeGrade(other.executeGrade) {}

/* Getter */
const std::string& Form::getName() const { return (name); }
const bool& Form::getSignFlag() const { return (signFlag); }
const int& Form::getSignGrade() const { return (signGrade); }
const int& Form::getExecuteGrade() const { return (executeGrade); }

/* Member Function */
void Form::beSigned(Bureaucrat& bureaucrat) {
  if (this->getSignGrade() < bureaucrat.getGrade()) {
    throw Form::GradeTooLowException();
  }
  this->signFlag = true;
}

/* Exception Class-Function */
const char* Form::GradeTooHighException::what() const throw() {
  return "Form: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Form: Grade is too low";
}

/* Insertion operator */
std::ostream& operator<<(std::ostream& output, const Form& form) {
  output << "form: " << form.getName() << " / "
         << "signed: " << (form.getSignFlag() ? "true" : "false") << " / "
         << "singGrade: " << form.getSignGrade() << " / "
         << "executeGrade: " << form.getExecuteGrade();
  return (output);
}