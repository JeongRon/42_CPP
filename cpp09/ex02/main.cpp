#include "PmergeMe.hpp"

int main(int ac, char** av) {
  try {
    if (ac < 2) {
      throw std::runtime_error("Error: empty numbers");
    } else {
      // execute
      PmergeMe pmerge;
      pmerge.inputNumbers(ac, av);
      //   pmerge.mergeInsertSortDeque();
      //   pmerge.mergeInsertSortQueue();
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}