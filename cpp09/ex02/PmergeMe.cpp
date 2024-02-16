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
  dequeInputNumbers(ac, av);

  int pairCount = dequePair.size();

  if (pairCount == 1) {
    return;
  }
  // search && push - pairA, pairB
  int indexPairB = pairCount / 2;
  int pairA, pairB;
  for (int i = 0; i < indexPairB; i++) {
    pairA = dequePair[i].first;
    pairB = dequePair[i + indexPairB].first;
    if (pairA > pairB) {
      dequePair[i].second.push_back(pairB);
    } else {
      dequePair[i].swap(dequePair[i + indexPairB]);
      dequePair[i].second.push_back(pairA);
    }
  }
  // recursive
  dequeMergeInsertSort(pairCount / 2);
  // insert remain
  if (pairCount % 2 == 1) {
    std::pair<int, std::deque<int> > insertPair = dequePair[pairCount - 1];
    dequeInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
  }
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

    std::deque<std::pair<int, std::deque<int> > >::iterator it;
    for (it = dequePair.begin(); it != dequePair.end(); it++) {
      if (it->first == pushNumber) {
        throw std::runtime_error("Error: duplicate number");
      }
    }
    std::deque<int> emptyDeque;
    dequePair.push_back(
        std::pair<int, std::deque<int> >(pushNumber, emptyDeque));
    unsortedDeque.push_back(pushNumber);
  }

  if (unsortedDeque.size() > 100000)
    throw std::runtime_error("Error: too many numbers (lower count -> 100000)");
}

void PmergeMe::dequeMergeInsertSort(int pairCount) {
  // stop point
  if (pairCount == 1) {
    sortedDeque.push_back(dequePair[1]);
    dequePair[0].second.pop_back();
    sortedDeque.push_back(dequePair[0]);
    return;
  }
  // search && push - pairA, pairB
  int indexPairB = pairCount / 2;
  int pairA, pairB;
  for (int i = 0; i < indexPairB; i++) {
    pairA = dequePair[i].first;
    pairB = dequePair[i + indexPairB].first;
    if (pairA > pairB) {
      dequePair[i].second.push_back(pairB);
    } else {
      dequePair[i].swap(dequePair[i + indexPairB]);
      dequePair[i].second.push_back(pairA);
    }
  }
  // recursive
  dequeMergeInsertSort(pairCount / 2);
  // insert - remain
  std::pair<int, std::deque<int> > insertPair;
  if (pairCount % 2 == 1) {
    insertPair = dequePair[pairCount - 1];
    dequeInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
  }
  // insert - pair
  std::deque<int> jacobsthal = dequeJacobsthalIndex(pairCount);
  std::deque<int>::iterator iterIndex;
  for (iterIndex = jacobsthal.begin(); iterIndex != jacobsthal.end();
       iterIndex++) {
    insertPair = dequePair[*iterIndex];
    dequeInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
  }
}

std::deque<int> PmergeMe::dequeJacobsthalIndex(int pairCount) {
  std::deque<int> jacobsthalDeque;
  int jacobsthalNum = 1;
  int jacobA = 1;
  int jacobB = 1;
  int jacobTmp = 1;
  bool finish = false;
  int pairB;
  int point_index;

  while (true) {
    point_index = pairCount;
    pairB = sortedDeque[jacobsthalNum - 1].second.back();
    sortedDeque[jacobsthalNum - 1].second.pop_back();

    std::deque<std::pair<int, std::deque<int> > >::iterator it;
    for (it = dequePair.begin() + pairCount; it != dequePair.end();
         it++, point_index++) {
      if (it->first == pairB) {
        jacobsthalDeque.push_back(point_index);
        break;
      }
    }

    if (jacobsthalNum == 1 || jacobsthalNum == jacobA + 1) {
      if (finish) break;
      jacobTmp = jacobA * 2 + jacobB;
      jacobA = jacobB;
      jacobB = jacobTmp;
      jacobsthalNum = jacobB;
      if (jacobsthalNum - 1 >= pairCount - 1) {
        jacobsthalNum = pairCount;
        finish = true;
      }
    } else {
      jacobsthalNum--;
    }
  }
  return jacobsthalDeque;
}

void PmergeMe::dequeInsertPair(std::pair<int, std::deque<int> > insertPair,
                               int pairB, int low, int high) {
  // stop point
  if (high == low) {
    if (sortedDeque[high].first > pairB)
      sortedDeque.insert(sortedDeque.begin() + high, insertPair);
    else if (sortedDeque[high].first < pairB)
      sortedDeque.insert(sortedDeque.begin() + high + 1, insertPair);
    return;
  }
  int mid = (low + high) / 2;
  if (pairB < sortedDeque[mid].first) {
    dequeInsertPair(insertPair, pairB, low, mid);
  } else if (sortedDeque[mid].first < pairB) {
    if (mid == low)
      dequeInsertPair(insertPair, pairB, mid + 1, high);
    else
      dequeInsertPair(insertPair, pairB, mid, high);
  }
}

/* Vector */
void PmergeMe::executeVector(int ac, char** av) {
  vectorInputNumbers(ac, av);

  int pairCount = vectorPair.size();

  if (pairCount == 1) {
    return;
  }
  // search && push - pairA, pairB
  int indexPairB = pairCount / 2;
  int pairA, pairB;
  for (int i = 0; i < indexPairB; i++) {
    pairA = vectorPair[i].first;
    pairB = vectorPair[i + indexPairB].first;
    if (pairA > pairB) {
      vectorPair[i].second.push_back(pairB);
    } else {
      vectorPair[i].swap(vectorPair[i + indexPairB]);
      vectorPair[i].second.push_back(pairA);
    }
  }
  // recursive
  vectorMergeInsertSort(pairCount / 2);
  // insert remain
  if (pairCount % 2 == 1) {
    std::pair<int, std::vector<int> > insertPair = vectorPair[pairCount - 1];
    vectorInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
  }
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

    std::vector<std::pair<int, std::vector<int> > >::iterator it;
    for (it = vectorPair.begin(); it != vectorPair.end(); it++) {
      if (it->first == pushNumber) {
        throw std::runtime_error("Error: duplicate number");
      }
    }
    std::vector<int> emptyVector;
    vectorPair.push_back(
        std::pair<int, std::vector<int> >(pushNumber, emptyVector));
    unsortedVector.push_back(pushNumber);
  }
  if (unsortedVector.size() > 100000)
    throw std::runtime_error("Error: too many numbers (lower count -> 100000)");
}

void PmergeMe::vectorMergeInsertSort(int pairCount) {
  // stop point
  if (pairCount == 1) {
    sortedVector.push_back(vectorPair[1]);
    vectorPair[0].second.pop_back();
    sortedVector.push_back(vectorPair[0]);
    return;
  }
  // search && push - pairA, pairB
  int indexPairB = pairCount / 2;
  int pairA, pairB;
  for (int i = 0; i < indexPairB; i++) {
    pairA = vectorPair[i].first;
    pairB = vectorPair[i + indexPairB].first;
    if (pairA > pairB) {
      vectorPair[i].second.push_back(pairB);
    } else {
      vectorPair[i].swap(vectorPair[i + indexPairB]);
      vectorPair[i].second.push_back(pairA);
    }
  }
  // recursive
  vectorMergeInsertSort(pairCount / 2);
  // insert - remain
  std::pair<int, std::vector<int> > insertPair;
  if (pairCount % 2 == 1) {
    insertPair = vectorPair[pairCount - 1];
    vectorInsertPair(insertPair, insertPair.first, 0, sortedVector.size() - 1);
  }
  // insert - pair
  std::vector<int> jacobsthal = vectorJacobsthalIndex(pairCount);
  std::vector<int>::iterator iterIndex;
  for (iterIndex = jacobsthal.begin(); iterIndex != jacobsthal.end();
       iterIndex++) {
    insertPair = vectorPair[*iterIndex];
    vectorInsertPair(insertPair, insertPair.first, 0, sortedVector.size() - 1);
  }
}

std::vector<int> PmergeMe::vectorJacobsthalIndex(int pairCount) {
  std::vector<int> jacobsthalVector;
  int jacobsthalNum = 1;
  int jacobA = 1;
  int jacobB = 1;
  int jacobTmp = 1;
  bool finish = false;
  int pairB;
  int point_index;

  while (true) {
    point_index = pairCount;
    pairB = sortedVector[jacobsthalNum - 1].second.back();
    sortedVector[jacobsthalNum - 1].second.pop_back();

    std::vector<std::pair<int, std::vector<int> > >::iterator it;
    for (it = vectorPair.begin() + pairCount; it != vectorPair.end();
         it++, point_index++) {
      if (it->first == pairB) {
        jacobsthalVector.push_back(point_index);
        break;
      }
    }

    if (jacobsthalNum == 1 || jacobsthalNum == jacobA + 1) {
      if (finish) break;
      jacobTmp = jacobA * 2 + jacobB;
      jacobA = jacobB;
      jacobB = jacobTmp;
      jacobsthalNum = jacobB;
      if (jacobsthalNum - 1 >= pairCount - 1) {
        jacobsthalNum = pairCount;
        finish = true;
      }
    } else {
      jacobsthalNum--;
    }
  }
  return jacobsthalVector;
}

void PmergeMe::vectorInsertPair(std::pair<int, std::vector<int> > insertPair,
                                int pairB, int low, int high) {
  // stop point
  if (high == low) {
    if (sortedVector[high].first > pairB)
      sortedVector.insert(sortedVector.begin() + high, insertPair);
    else if (sortedVector[high].first < pairB)
      sortedVector.insert(sortedVector.begin() + high + 1, insertPair);
    return;
  }
  int mid = (low + high) / 2;
  if (pairB < sortedVector[mid].first) {
    vectorInsertPair(insertPair, pairB, low, mid);
  } else if (sortedVector[mid].first < pairB) {
    if (mid == low)
      vectorInsertPair(insertPair, pairB, mid + 1, high);
    else
      vectorInsertPair(insertPair, pairB, mid, high);
  }
}

void PmergeMe::execute(int ac, char** av) {
  std::clock_t start, end;

  start = std::clock();
  executeDeque(ac, av);
  end = std::clock();

  dequeTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

  start = std::clock();
  executeVector(ac, av);
  end = std::clock();

  vectorTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

  printResult();
}

void PmergeMe::printResult() {
  if (dequePair.size() != sortedVector.size())
    throw std::runtime_error("sorted check size error");

  std::deque<std::pair<int, std::deque<int> > >::iterator iterDeque =
      sortedDeque.begin();
  std::vector<std::pair<int, std::vector<int> > >::iterator iterVector =
      sortedVector.begin();
  for (; iterDeque != sortedDeque.end() && iterVector != sortedVector.end();
       iterDeque++, iterVector++) {
    if (iterDeque->first != iterVector->first)
      throw std::runtime_error("sorted check order error");
  }

  // PRINT
  std::deque<int>::iterator it;
  std::cout << "Before: ";
  for (it = unsortedDeque.begin(); it != unsortedDeque.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "After:  ";
  for (iterDeque = sortedDeque.begin(); iterDeque != sortedDeque.end();
       iterDeque++) {
    std::cout << iterDeque->first << " ";
  }
  std::cout << std::endl;
  std::cout << "Time to process a range of " << sortedDeque.size()
            << " elements with std::deque : " << dequeTime << " us"
            << std::endl;
  std::cout << "Time to process a range of " << sortedVector.size()
            << " elements with std::vector : " << vectorTime << " us"
            << std::endl;
}