#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

/* Abstract Class */
class AForm {
 private:
  const std::string name;
  bool signFlag;
  const int signGrade;
  const int executeGrade;
  std::string target;

  /* Block */
  AForm();
  AForm& operator=(const AForm& other);

 public:
  /* Lifecycle Functions */
  AForm(const std::string name, const int signGrade, const int executeGrade,
        const std::string& target);
  virtual ~AForm();
  AForm(const AForm& other);

  /* Getter */
  const std::string& getName() const;
  const bool& getSignFlag() const;
  const int& getSignGrade() const;
  const int& getExecuteGrade() const;
  const std::string& getTarget() const;

  /* Member Function */
  void beSigned(Bureaucrat& bureaucrat);
  // pure virtual fucntion
  virtual void execute(Bureaucrat const& executor) const = 0;

  /* Exception Class-Function */
  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
};

/* Insertion operator */
std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif