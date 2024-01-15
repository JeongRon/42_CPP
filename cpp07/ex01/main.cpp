#include "iter.hpp"

int main(void) {
  int i[5] = {0, 1, 2, 3, 4};
  double d[5] = {0.1, 1.2, 2.3, 3.4, 4.5};
  char c[5] = {'a', 'b', 'c', 'd', 'e'};

  iter(i, sizeof(i) / sizeof(*i), print);
  std::cout << "------------------------------------------" << std::endl;
  iter(d, sizeof(d) / sizeof(*d), print);
  std::cout << "------------------------------------------" << std::endl;
  iter(c, sizeof(c) / sizeof(*c), print);

  return 0;
}