#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac == 2) {
    std::string input = std::string(av[1]);
    ScalarConverter::convert(input);
  } else {
    std::cout << "Please Input One Literal" << std::endl;
  }
  return 0;
}