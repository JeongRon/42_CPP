#include "PmergeMe.hpp"

/* OCF */
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
}

/* Deque */
void PmergeMe::executeDeque(int ac, char** av) {
  PmergeMe::dequeInputNumbers(ac, av);

  if (unsortedDeque.size() == 1) {
    sortedDeque.push_back(unsortedDeque[0]);
    return;
  }
  std::deque<std::pair<int, int> > dequePair;
  std::deque<int>::iterator it = unsortedDeque.begin();
  int pairA, pairB;
  int remain = -1;

  if (unsortedDeque.size() % 2 == 1) remain = unsortedDeque.back();

  for (; it != unsortedDeque.end() && (it + 1) != unsortedDeque.end();
       it += 2) {
    pairA = *it;
    pairB = *(it + 1);
    if (pairA > pairB)
      dequePair.push_back(std::pair<int, int>(pairA, pairB));
    else
      dequePair.push_back(std::pair<int, int>(pairB, pairA));
  }

  sortedDeque = PmergeMe::dequeMergeInsertSort(dequePair);
  if (remain != -1)
    PmergeMe::dequeInsertPairB(sortedDeque, remain, 0, sortedDeque.size() - 1);
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

    std::deque<int>::iterator it =
        std::find(unsortedDeque.begin(), unsortedDeque.end(), pushNumber);
    if (it != unsortedDeque.end()) {
      throw std::runtime_error("Error: duplicate number");
    }
    unsortedDeque.push_back(number);
  }
}

std::deque<int> PmergeMe::dequeMergeInsertSort(
    std::deque<std::pair<int, int> > dequePair) {
  std::deque<int> insertDeque;
  std::deque<std::pair<int, int> >::iterator iter = dequePair.begin();

  // // TEST
  // std::cout << "------ dequePair -------" << std::endl;
  // std::deque<std::pair<int, int> >::iterator test = dequePair.begin();
  // for (; test != dequePair.end(); test++) {
  //   std::cout << test->first << " " << test->second << std::endl;
  // }
  // std::cout << "-----------------------" << std::endl;
  // // TEST

  // stop point
  if (dequePair.size() == 1) {
    insertDeque.push_back(iter->second);
    insertDeque.push_back(iter->first);
    return insertDeque;
  }

  // dequePair 에서 더 divide
  std::deque<std::pair<int, int> > nowPair;
  int pairA, pairB;
  int remain = -1;
  for (; iter != dequePair.end() && (iter + 1) != dequePair.end(); iter += 2) {
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
  // 재귀로 insertDeque 받아오기
  insertDeque = dequeMergeInsertSort(nowPair);
  // // TEST
  // std::cout << "------ (GET)insertDeque -------" << std::endl;
  // std::deque<int>::iterator ppp = insertDeque.begin();
  // for (; ppp != insertDeque.end(); ppp++) {
  //   std::cout << *ppp << " ";
  // }
  // std::cout << std::endl;
  // std::cout << "-----------------------" << std::endl;
  // // TEST
  if (remain != -1)
    PmergeMe::dequeInsertPairB(insertDeque, remain, 0, insertDeque.size() - 1);
  // // TEST
  // std::cout << "------ (REMAIN)insertDeque : " << remain << " -------"
  //           << std::endl;
  // ppp = insertDeque.begin();
  // for (; ppp != insertDeque.end(); ppp++) {
  //   std::cout << *ppp << " ";
  // }
  // std::cout << std::endl;
  // std::cout << "-----------------------" << std::endl;
  // // TEST
  std::deque<int> order = PmergeMe::dequeJacobsthal(insertDeque);
  std::deque<int>::iterator orderIter = order.begin();
  bool frontFlag = true;
  for (; orderIter != order.end(); orderIter++) {
    pairA = *orderIter;

    std::deque<std::pair<int, int> >::iterator pairIter = dequePair.begin();
    for (; pairIter != dequePair.end(); pairIter++) {
      if (pairIter->first == pairA) {
        pairB = pairIter->second;
        break;
      }
    }
    if (frontFlag) {
      insertDeque.push_front(pairB);
      frontFlag = false;
    } else {
      std::deque<int>::iterator it =
          std::find(insertDeque.begin(), insertDeque.end(), pairA);
      int high = it - insertDeque.begin();
      // // TEST
      // std::cout << "------------------" << std::endl;
      // std::cout << "pairA : " << pairA << std::endl;
      // std::cout << "pairB : " << pairB << std::endl;
      // std::cout << "high : " << high << std::endl;
      // std::cout << "------------------" << std::endl;
      // // TEST
      PmergeMe::dequeInsertPairB(insertDeque, pairB, 0, high - 1);
    }
    // // TEST
    // std::cout << "------ (PUSH) insertDeque : " << pairB << " -------"
    //           << std::endl;
    // std::deque<int>::iterator aaa = insertDeque.begin();
    // for (; aaa != insertDeque.end(); aaa++) {
    //   std::cout << *aaa << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "-----------------------" << std::endl;
    // // TEST
  }
  return insertDeque;
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
  // // TEST
  // std::cout << "-------- jacobsthal --------" << std::endl;
  // std::deque<int>::iterator tt = jacobsthalDeque.begin();
  // for (; tt != jacobsthalDeque.end(); tt++) {
  //   std::cout << *tt << " ";
  // }
  // std::cout << std::endl;
  // std::cout << "-----------------------" << std::endl;
  // // TEST
  return jacobsthalDeque;
}

void PmergeMe::dequeInsertPairB(std::deque<int>& insertDeque, int pairB,
                                int low, int high) {
  // stop point
  if (high == low) {
    if (insertDeque[high] > pairB)
      insertDeque.insert(insertDeque.begin() + high, pairB);
    else if (insertDeque[high] < pairB)
      insertDeque.insert(insertDeque.begin() + high + 1, pairB);
    return;
  }
  int mid = (low + high) / 2;
  if (pairB < insertDeque[mid]) {
    PmergeMe::dequeInsertPairB(insertDeque, pairB, low, mid);
  } else if (insertDeque[mid] < pairB) {
    if (mid == low)
      PmergeMe::dequeInsertPairB(insertDeque, pairB, mid + 1, high);
    else
      PmergeMe::dequeInsertPairB(insertDeque, pairB, mid, high);
  }
}

/* Vector */
void PmergeMe::executeVector(int ac, char** av) {
  PmergeMe::vectorInputNumbers(ac, av);

  if (unsortedVector.size() == 1) {
    sortedVector.push_back(unsortedVector[0]);
    return;
  }
  std::vector<std::pair<int, int> > vectorPair;
  std::vector<int>::iterator it = unsortedVector.begin();
  int pairA, pairB;
  int remain = -1;

  if (unsortedVector.size() % 2 == 1) remain = unsortedVector.back();

  for (; it != unsortedVector.end() && (it + 1) != unsortedVector.end();
       it += 2) {
    pairA = *it;
    pairB = *(it + 1);
    if (pairA > pairB)
      vectorPair.push_back(std::pair<int, int>(pairA, pairB));
    else
      vectorPair.push_back(std::pair<int, int>(pairB, pairA));
  }

  sortedVector = PmergeMe::vectorMergeInsertSort(vectorPair);
  if (remain != -1)
    PmergeMe::vectorInsertPairB(sortedVector, remain, 0,
                                sortedVector.size() - 1);
}

void PmergeMe::vectorInputNumbers(int ac, char** av) {
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

    std::vector<int>::iterator it =
        std::find(unsortedVector.begin(), unsortedVector.end(), pushNumber);
    if (it != unsortedVector.end()) {
      throw std::runtime_error("Error: duplicate number");
    }
    unsortedVector.push_back(number);
  }
}

std::vector<int> PmergeMe::vectorMergeInsertSort(
    std::vector<std::pair<int, int> > vectorPair) {
  std::vector<int> insertVector;
  std::vector<std::pair<int, int> >::iterator iter = vectorPair.begin();

  // stop point
  if (vectorPair.size() == 1) {
    insertVector.push_back(iter->second);
    insertVector.push_back(iter->first);
    return insertVector;
  }

  // vectorPair 에서 더 divide
  std::vector<std::pair<int, int> > nowPair;
  int pairA, pairB;
  int remain = -1;
  for (; iter != vectorPair.end() && (iter + 1) != vectorPair.end();
       iter += 2) {
    // vectorPair 2개씩 추출해서 nowPair에 넣기
    pairA = iter->first;
    pairB = (iter + 1)->first;
    if (pairA > pairB)
      nowPair.push_back(std::pair<int, int>(pairA, pairB));
    else
      nowPair.push_back(std::pair<int, int>(pairB, pairA));
  }
  // remain
  if (iter != vectorPair.end()) {
    remain = iter->first;
  }
  // 재귀로 insertVector 받아오기
  insertVector = vectorMergeInsertSort(nowPair);
  if (remain != -1)
    PmergeMe::vectorInsertPairB(insertVector, remain, 0,
                                insertVector.size() - 1);
  // insertVector 안에 pairB 추가하기
  std::vector<int> order = PmergeMe::vectorJacobsthal(insertVector);
  std::vector<int>::iterator orderIter = order.begin();
  bool frontFlag = true;
  for (; orderIter != order.end(); orderIter++) {
    pairA = *orderIter;

    std::vector<std::pair<int, int> >::iterator pairIter = vectorPair.begin();
    for (; pairIter != vectorPair.end(); pairIter++) {
      if (pairIter->first == pairA) {
        pairB = pairIter->second;
        break;
      }
    }
    if (frontFlag) {
      insertVector.insert(insertVector.begin(), pairB);
      frontFlag = false;
    } else {
      std::vector<int>::iterator it =
          std::find(insertVector.begin(), insertVector.end(), pairA);
      int high = it - insertVector.begin();
      PmergeMe::vectorInsertPairB(insertVector, pairB, 0, high - 1);
    }
  }
  return insertVector;
}

std::vector<int> PmergeMe::vectorJacobsthal(std::vector<int> insertVector) {
  std::vector<int> jacobsthalVector;
  int count = insertVector.size();
  int jacobsthalA = 1;
  int jacobsthalB = 1;
  int jacobsthalNum = -1;

  jacobsthalVector.push_back(insertVector[0]);
  while (jacobsthalNum != count) {
    jacobsthalNum = jacobsthalA * 2 + jacobsthalB;
    jacobsthalA = jacobsthalB;
    jacobsthalB = jacobsthalNum;
    if (jacobsthalNum >= count) jacobsthalNum = count;

    for (int i = jacobsthalNum; jacobsthalA < i; i--) {
      jacobsthalVector.push_back(insertVector[i - 1]);
    }
  }
  return jacobsthalVector;
}

void PmergeMe::vectorInsertPairB(std::vector<int>& insertVector, int pairB,
                                 int low, int high) {
  // stop point
  if (high == low) {
    if (insertVector[high] > pairB)
      insertVector.insert(insertVector.begin() + high, pairB);
    else if (insertVector[high] < pairB)
      insertVector.insert(insertVector.begin() + high + 1, pairB);
    return;
  }
  int mid = (low + high) / 2;
  if (pairB < insertVector[mid]) {
    PmergeMe::vectorInsertPairB(insertVector, pairB, low, mid);
  } else if (insertVector[mid] < pairB) {
    if (mid == low)
      PmergeMe::vectorInsertPairB(insertVector, pairB, mid + 1, high);
    else
      PmergeMe::vectorInsertPairB(insertVector, pairB, mid, high);
  }
}

void PmergeMe::execute(int ac, char** av) {
  std::clock_t start, end;

  start = std::clock();
  PmergeMe::executeDeque(ac, av);
  end = std::clock();

  dequeTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

  start = std::clock();
  PmergeMe::executeVector(ac, av);
  end = std::clock();

  vectorTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

  PmergeMe::printResult();
}

void PmergeMe::printResult() {
  if (sortedDeque.size() != sortedVector.size())
    throw std::runtime_error("sorted check size error");

  std::deque<int>::iterator iterDeque = sortedDeque.begin();
  std::vector<int>::iterator iterVector = sortedVector.begin();
  for (; iterDeque != sortedDeque.end() && iterVector != sortedVector.end();
       iterDeque++, iterVector++) {
    // TEST
    // std::cout << *iterDeque << " " << *iterVector << std::endl;
    // TEST
    if (*iterDeque != *iterVector)
      throw std::runtime_error("sorted check order error");
  }

  // PRINT
  std::cout << "Before: ";
  for (iterDeque = unsortedDeque.begin(); iterDeque != unsortedDeque.end();
       iterDeque++) {
    std::cout << *iterDeque << " ";
  }
  std::cout << std::endl;
  std::cout << "After:  ";
  for (iterDeque = sortedDeque.begin(); iterDeque != sortedDeque.end();
       iterDeque++) {
    std::cout << *iterDeque << " ";
  }
  std::cout << std::endl;
  std::cout << "Time to process a range of " << sortedDeque.size()
            << " elements with std::deque : " << dequeTime << " us"
            << std::endl;
  std::cout << "Time to process a range of " << sortedVector.size()
            << " elements with std::vector : " << vectorTime << " us"
            << std::endl;
}