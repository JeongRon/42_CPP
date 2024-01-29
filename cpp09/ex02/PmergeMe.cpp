#include "PmergeMe.hpp"

/* OCF */
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
}

/* Member Function */
void PmergeMe::inputNumbers(int ac, char** av) {
  for (int i = 1; i < ac; i++) {
    for (int j = 0;; j++) {
      if (av[i][j] == '\0') break;

      if (av[i][j] < 48 || av[i][j] > 57)
        throw std::runtime_error("Error: not a number");
    }

    char* endptr;
    double number = strtod(av[i], &endptr);
    if (*endptr != '\0') throw std::runtime_error("Error: invalid number");
    if (number < 0) throw std::runtime_error("Error: negative number");
    if (number > INT_MAX) throw std::runtime_error("Error: INT_MAX number");
    int pushNumber = static_cast<int>(number);
    unorderedNumbers.push_back(pushNumber);
  }

  //   std::cout << "---------------- [unorderedNumbers] ----------------"
  //             << std::endl;
  //   std::deque<int>::iterator it = unorderedNumbers.begin();
  //   for (; it != unorderedNumbers.end(); ++it) {
  //     std::cout << *it << std::endl;
  //   }
  //   std::cout << "---------------------------------------------------"
  //             << std::endl;
}

void PmergeMe::mergeInsertSortDeque() {
  // deque map 넣기
  // 계산 하기?
}
