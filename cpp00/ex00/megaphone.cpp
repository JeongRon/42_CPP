#include <cctype>
#include <iostream>

int main(int ac, char **av) {
  char c;
  if (ac == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (int i = 1; i < ac; i++) {
      for (int j = 0; av[i][j]; j++) {
        if (std::islower(av[i][j])) {
          c = std::toupper(av[i][j]);
          std::cout << c;
        } else
          std::cout << av[i][j];
      }
    }
    std::cout << std::endl;
  }
  return 0;
}