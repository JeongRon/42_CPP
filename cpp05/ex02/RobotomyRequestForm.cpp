#include "RobotomyRequestForm.hpp"

#include "Bureaucrat.hpp"

/* Block */
RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& form) {
  (void)form;
  return (*this);
}

/* Lifecycle Functions */
RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
    : AForm(name, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
    : AForm(form) {}

/* Member Function */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  // sign check
  if (this->getSignFlag() == false) throw AForm::NotSignedException();
  // execute check
  if (this->getExecuteGrade() < executor.getGrade())
    throw AForm::GradeTooHighException();
  // RobotomyRequestForm execute
  RobotomyRequestForm::action();
}

void RobotomyRequestForm::action() const {
  std::srand(static_cast<unsigned>(std::time(NULL)));
  int randomFlag = std::rand() % 2;
  if (randomFlag == 0)
    std::cout << "drilling noises: whirr whirr whirr" << std::endl;
  else
    throw RobotomyRequestForm::RobotFailedException();
}

/* Exception Class-Function */
const char* RobotomyRequestForm::RobotFailedException::what() const throw() {
  return "RobotomyRequestForm: Failed";
}