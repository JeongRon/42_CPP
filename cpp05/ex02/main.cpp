#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}