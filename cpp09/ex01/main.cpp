#include "RPN.hpp"

int main(int ac, char **av) {
  try {
    if (ac == 2) {
      RPN calculator = RPN();
      std::string expression(av[1]);
      calculator.executeRpn(expression);
    } else {
      throw std::runtime_error("Error: Invalid Input");
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}