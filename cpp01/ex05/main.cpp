#include "Harl.hpp"

int main(void) {
  Harl harl;

  harl.complain("debug");
  std::cout << "\n";
  harl.complain("info");
  std::cout << "\n";
  harl.complain("warning");
  std::cout << "\n";
  harl.complain("error");
  return 0;
}