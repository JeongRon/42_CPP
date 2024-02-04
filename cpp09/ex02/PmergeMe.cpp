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
void PmergeMe::executeDeque(int ac, char** av) {
  PmergeMe::dequeInputNumbers(ac, av);

  if (unsortedContainer.size() <= 1)
    return;  // print
             // (1) make pair
  std::deque<std::pair<int, int> > dequePair;
  std::deque<int>::iterator it = unsortedContainer.begin();
  int pairA, pairB;
  int remain = -1;

  if (unsortedContainer.size() % 2 == 1) remain = unsortedContainer.back();

  for (; it != unsortedContainer.end() && (it + 1) != unsortedContainer.end();
       it += 2) {
    pairA = *it;
    pairB = *(it + 1);
    if (pairA > pairB)
      dequePair.push_back(std::pair<int, int>(pairA, pairB));
    else
      dequePair.push_back(std::pair<int, int>(pairB, pairA));
  }

  std::deque<int> sortedContainer = PmergeMe::dequeMergeInsertSort(dequePair);

  // remain 있으면 sortedContainer에 마지막으로 넣기

  // PRINT
}

void PmergeMe::dequeInputNumbers(int ac, char** av) {
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

    std::deque<int>::iterator it = std::find(
        unsortedContainer.begin(), unsortedContainer.end(), pushNumber);
    if (it != unsortedContainer.end()) {
      throw std::runtime_error("Error: duplicate number");
    }
    unsortedContainer.push_back(number);
  }
}

std::deque<int> PmergeMe::dequeMergeInsertSort(
    std::deque<std::pair<int, int> > dequePair) {
  std::deque<int> insertDeque;
  std::deque<std::pair<int, int> >::iterator iter = dequePair.begin();

  // stop point
  if (dequePair.size() == 1) {
    insertDeque.push_back(iter->first);
    insertDeque.push_back(iter->second);
    return insertDeque;
  } else {
    // dequePair 에서 더 divide
    std::deque<std::pair<int, int> > nowPair;
    int pairA, pairB;
    int remain = -1;
    for (; iter != dequePair.end() && (iter + 1) != dequePair.end();
         iter += 2) {
      // dequePair에서 2개씩 추출해서 nowPair에 넣기
      pairA = iter->first;
      pairB = (iter + 1)->first;
      if (pairA > pairB)
        nowPair.push_back(std::pair<int, int>(pairA, pairB));
      else
        nowPair.push_back(std::pair<int, int>(pairB, pairA));
    }
    // remain
    if (iter != dequePair.end()) {
      remain = iter->first;
    }
    insertDeque = dequeMergeInsertSort(nowPair);
    // 받은 isertDeque를 야콥스탈 활용 -> pairB를 insert 후 리턴
    std::deque<int> order = PmergeMe::dequeJacobsthal(insertDeque);
    // dequePair에서 order 의 요소값들 찾아서 insert
    std::deque<int>::iterator orderIter = order.begin();
    for (; orderIter != order.end(); orderIter++) {
      int pairA = *orderIter;
      // iter = dequePair.find(pairA); // 여기부터
      // int pairB =
    }
    return insertDeque;
  }
}

std::deque<int> PmergeMe::dequeJacobsthal(std::deque<int> insertDeque) {
  std::deque<int> jacobsthalDeque;
  int count = insertDeque.size();
  int jacobsthalA = 1;
  int jacobsthalB = 1;
  int jacobsthalNum = -1;

  jacobsthalDeque.push_back(insertDeque[0]);
  while (jacobsthalNum != count) {
    jacobsthalNum = jacobsthalA * 2 + jacobsthalB;
    jacobsthalA = jacobsthalB;
    jacobsthalB = jacobsthalNum;
    if (jacobsthalNum >= count) jacobsthalNum = count;

    for (int i = jacobsthalNum; jacobsthalA < i; i--) {
      jacobsthalDeque.push_back(insertDeque[i - 1]);
    }
  }
  return jacobsthalDeque;
}