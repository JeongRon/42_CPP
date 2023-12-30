#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat {
 private:
  const std::string name;
  int grade;

  /* Block */
  Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& other);

 public:
  /* Lifecycle Functions */
  Bureaucrat(const std::string name, const int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& other);

  /* Getter */
  const std::string& getName() const;
  const int& getGrade() const;

  /* Member Function */
  void increaseGrade();
  void decreaseGrade();
  void signForm(Form& form);

  /* Exception Class-Function */
  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
};

/* Insertion operator */
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif