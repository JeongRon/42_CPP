#include "Bureaucrat.hpp"

#include "AForm.hpp"

/* Block */
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  (void)other;
  return (*this);
}

/* Lifecycle Functions */
Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : name(name), grade(grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {}

/* Getter */
const std::string& Bureaucrat::getName() const { return (this->name); }

const int& Bureaucrat::getGrade() const { return (this->grade); }

/* Member Function */
void Bureaucrat::increaseGrade() {
  if (grade == 1) throw Bureaucrat::GradeTooHighException();
  grade--;
}

void Bureaucrat::decreaseGrade() {
  if (grade == 150) throw Bureaucrat::GradeTooLowException();
  grade++;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn’t sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

/* Exception Class-Function */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat: Grade is too low";
}

/* Insertion operator */
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat) {
  output << bureaucrat.getName() << ", bureaucrat grade "
         << bureaucrat.getGrade();

  return (output);
}