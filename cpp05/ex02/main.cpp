#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::cout << "-----------------------------" << std::endl;
  try {
    Bureaucrat Bob("Bob", 50);
    ShrubberyCreationForm ShrubberyForm("SHRUBBERY");
    ShrubberyForm.beSigned(Bob);
    Bob.executeForm(ShrubberyForm);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;
  try {
    Bureaucrat Ron("Ron", 40);
    RobotomyRequestForm Robot("Robot");
    Robot.beSigned(Ron);
    Ron.executeForm(Robot);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;
  try {
    Bureaucrat Tom("Tom", 5);
    PresidentialPardonForm Pardon("Pardon");
    Pardon.beSigned(Tom);
    Tom.executeForm(Pardon);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;

  return 0;
}