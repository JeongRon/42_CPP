#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
    Bureaucrat Bob("Ron", 40);
    RobotomyRequestForm Robot("Robot");
    Robot.beSigned(Bob);
    Bob.executeForm(Robot);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;
  // try {
  //   Bureaucrat Bob("Ron", 50);
  //   RobotomyRequestForm Robot("Robot");
  //   Robot.beSigned(Bob);
  //   Bob.executeForm(Robot);
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }
  std::cout << "----------------------------" << std::endl;

  return 0;
}