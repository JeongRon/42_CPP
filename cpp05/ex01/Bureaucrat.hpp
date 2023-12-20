#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat {
 private:
  const std::string name;
  int grade;

  Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& other);

 public:
  Bureaucrat(const std::string name, const int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& other);

  const std::string& getName() const;
  const int& getGrade() const;

  void increaseGrade();
  void decreaseGrade();
  void signForm(Form& form);

  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif