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
  std::set<int> dupCheck;
  std::queue<int> unorderedNumbers;

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

    std::set<int>::iterator it = dupCheck.find(number);
    if (it != dupCheck.end()) {
      throw std::runtime_error("Error: duplicate number");
    }
    dupCheck.insert(number);
    unorderedNumbers.push(pushNumber);
  }

  // std::cout << "-------------- [unorderedNumbers] --------------" <<
  // std::endl; while (!unorderedNumbers.empty()) {
  //   std::cout << unorderedNumbers.front() << " ";
  //   unorderedNumbers.pop();  // 맨 앞 요소 제거
  // }
  // std::cout << std::endl;
  // std::cout << "-----------------------------------------------" <<
  // std::endl;

  while (true) {
    std::size_t size = unorderedNumbers.size();
    if (size >= 2) {
      int a = unorderedNumbers.front();
      unorderedNumbers.pop();
      int b = unorderedNumbers.front();
      unorderedNumbers.pop();
      pairMap[a] = b;
      // std::cout << "Map -> key: " << a << " / value: " << pairMap[a]
      //           << std::endl;
    } else if (size == 1) {
      remain = unorderedNumbers.front();
      unorderedNumbers.pop();
      // std::cout << "Remain -> " << remain << std::endl;
      break;
    } else {
      remain = -1;
      // std::cout << "NOT Remain" << std::endl;
      break;
    }
  }
}

void PmergeMe::mergeInsertSortDeque() {
  // deque map 넣기
  // 계산 하기?
}
