#include "AForm.hpp"
#include "Intern.hpp"

int main(void) {
  std::cout << "----------------------------" << std::endl;
  Intern newIntern;

  AForm *formA;
  formA = newIntern.makeForm("robotomy request", "Bender");
  if (formA != NULL) {
    std::cout << *formA << std::endl;
    delete formA;
  }
  std::cout << "----------------------------" << std::endl;
  AForm *formB;
  formB = newIntern.makeForm("random doodle", "hmm..");
  if (formB != NULL) {
    std::cout << *formB << std::endl;
    std::cout << std::endl;
    delete formB;
  }
  std::cout << "----------------------------" << std::endl;
  return 0;
}