#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat lowBureaucrat("lowBureaucrat", 151);
    std::cout << lowBureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat highBureaucrat("highBureaucrat", 0);
    std::cout << highBureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat middleBureaucrat("middleBureaucrat", 50);
    std::cout << middleBureaucrat << std::endl;
    middleBureaucrat.decreaseGrade();
    std::cout << middleBureaucrat << std::endl;
    middleBureaucrat.increaseGrade();
    std::cout << middleBureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}