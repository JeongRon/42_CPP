#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
 private:
  const std::string name;
  bool signFlag;
  const int signGrade;
  const int executeGrade;

  Form();
  Form& operator=(const Form& other);

 public:
  Form(const std::string name, const int signGrade, const int executeGrade);
  ~Form();
  Form(const Form& other);

  const std::string& getName() const;
  const bool& getSignFlag() const;
  const int& getSignGrade() const;
  const int& getExecuteGrade() const;

  void beSigned(Bureaucrat& bureaucrat);

  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& output, const Form& form);

#endif