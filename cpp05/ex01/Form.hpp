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

  /* Block */
  Form();
  Form& operator=(const Form& other);

 public:
  /* Lifecycle Functions */
  Form(const std::string name, const int signGrade, const int executeGrade);
  ~Form();
  Form(const Form& other);

  /* Getter */
  const std::string& getName() const;
  const bool& getSignFlag() const;
  const int& getSignGrade() const;
  const int& getExecuteGrade() const;

  /* Member Function */
  void beSigned(Bureaucrat& bureaucrat);

  /* Exception Class-Function */
  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
};

/* Insertion operator */
std::ostream& operator<<(std::ostream& output, const Form& form);

#endif