#include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  (void)other;
  return (*this);
}

const std::string& Bureaucrat::getName() const { return (this->name); }

const int& Bureaucrat::getGrade() const { return (this->grade); }

void Bureaucrat::increaseGrade() {
  if (grade == 1) throw Bureaucrat::GradeTooHighException();
  grade--;
}

void Bureaucrat::decreaseGrade() {
  if (grade == 150) throw Bureaucrat::GradeTooLowException();
  grade++;
}

void Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn’t sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat: Grade is too low";
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat) {
  output << bureaucrat.getName() << ", bureaucrat grade "
         << bureaucrat.getGrade();

  return (output);
}