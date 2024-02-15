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

  int dequeCount = dequePair.size();

  if (dequeCount == 1) {
    return;
  }
  // search && push - pairA, pairB
  int indexPairB = dequeCount / 2;
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
  dequeMergeInsertSort(dequeCount / 2);
  // insert remain
  if (dequeCount % 2 == 1) {
    std::pair<int, std::deque<int> > insertPair = dequePair[dequeCount - 1];
    dequeInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
  }

  // // TEST CODE
  // std::deque<std::pair<int, std::deque<int> > >::iterator it;
  // for (it = sortedDeque.begin(); it != sortedDeque.end(); it++) {
  //   std::cout << it->first << " : [ ";
  //   for (std::deque<int>::iterator innerIt = it->second.begin();
  //        innerIt != it->second.end(); ++innerIt) {
  //     std::cout << *innerIt << ", ";
  //   }
  //   std::cout << " ]" << std::endl;
  // }
  // // TEST CODE
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

void PmergeMe::dequeMergeInsertSort(int dequeCount) {
  // stop point
  if (dequeCount == 1) {
    // << TEST CODE
    std::cout << "--------- release start / dequePair ----------" << std::endl;
    std::deque<std::pair<int, std::deque<int> > >::iterator it;
    for (it = dequePair.begin(); it != dequePair.end(); it++) {
      std::cout << it->first << " : [ ";
      for (std::deque<int>::iterator innerIt = it->second.begin();
           innerIt != it->second.end(); ++innerIt) {
        std::cout << *innerIt << ", ";
      }
      std::cout << " ]" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    // TEST CODE >>

    sortedDeque.push_back(dequePair[1]);
    dequePair[0].second.pop_back();
    sortedDeque.push_back(dequePair[0]);
    return;
  }

  // search && push - pairA, pairB
  int indexPairB = dequeCount / 2;
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

  // divide
  dequeMergeInsertSort(dequeCount / 2);

  // TEST CODE
  std::cout << "--------- sortedDeque -----------" << std::endl;
  std::deque<std::pair<int, std::deque<int> > >::iterator test;
  for (test = sortedDeque.begin(); test != sortedDeque.end(); test++) {
    std::cout << test->first << " : [ ";
    for (std::deque<int>::iterator innerIt = test->second.begin();
         innerIt != test->second.end(); ++innerIt) {
      std::cout << *innerIt << ", ";
    }
    std::cout << " ]" << std::endl;
  }
  // TEST CODE

  std::pair<int, std::deque<int> > insertPair;
  // insert - remain
  if (dequeCount % 2 == 1) {
    insertPair = dequePair[dequeCount - 1];
    dequeInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
    // TEST CODE
    std::cout << "------ add remain - sortedDeque ------" << std::endl;
    std::deque<std::pair<int, std::deque<int> > >::iterator test;
    for (test = sortedDeque.begin(); test != sortedDeque.end(); test++) {
      std::cout << test->first << " : [ ";
      for (std::deque<int>::iterator innerIt = test->second.begin();
           innerIt != test->second.end(); ++innerIt) {
        std::cout << *innerIt << ", ";
      }
      std::cout << " ]" << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
    // TEST CODE
  }
  // insert - pair
  std::deque<int> jacobsthal = dequeJacobsthalIndex(dequeCount);
  std::deque<int>::iterator iterIndex;
  for (iterIndex = jacobsthal.begin(); iterIndex != jacobsthal.end();
       iterIndex++) {
    insertPair = dequePair[*iterIndex];
    dequeInsertPair(insertPair, insertPair.first, 0, sortedDeque.size() - 1);
  }
}

std::deque<int> PmergeMe::dequeJacobsthalIndex(int dequeCount) {
  std::deque<int> jacobsthalDeque;
  int jacobsthalNum = 1;
  int jacobA = 1;
  int jacobB = 1;
  int jacobTmp = 1;
  bool finish = false;
  int pairB;
  int point_index;

  while (true) {
    point_index = dequeCount;
    pairB = sortedDeque[jacobsthalNum - 1].second.back();
    sortedDeque[jacobsthalNum - 1].second.pop_back();

    // pairB가 dequePair에서 pairA인 위치 찾기 -> point_index
    std::deque<std::pair<int, std::deque<int> > >::iterator it;
    for (it = dequePair.begin() + dequeCount; it != dequePair.end();
         it++, point_index++) {
      if (it->first == pairB) {
        jacobsthalDeque.push_back(point_index);
        break;
      }
    }

    // 야콥 스타일 순서 갱신
    if (jacobsthalNum == 1 || jacobsthalNum == jacobA + 1) {
      if (finish) break;
      jacobTmp = jacobA * 2 + jacobB;
      jacobA = jacobB;
      jacobB = jacobTmp;
      jacobsthalNum = jacobB;
      if (jacobsthalNum - 1 >= dequeCount - 1) {
        jacobsthalNum = dequeCount;
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
    PmergeMe::dequeInsertPair(insertPair, pairB, low, mid);
  } else if (sortedDeque[mid].first < pairB) {
    if (mid == low)
      PmergeMe::dequeInsertPair(insertPair, pairB, mid + 1, high);
    else
      PmergeMe::dequeInsertPair(insertPair, pairB, mid, high);
  }
}

// /* Vector */
// void PmergeMe::executeVector(int ac, char** av) {
//   PmergeMe::vectorInputNumbers(ac, av);

//   if (unsortedVector.size() == 1) {
//     sortedVector.push_back(unsortedVector[0]);
//     return;
//   }
//   std::vector<std::pair<int, int>> vectorPair;
//   std::vector<int>::iterator it = unsortedVector.begin();
//   int pairA, pairB;
//   int remain = -1;

//   if (unsortedVector.size() % 2 == 1) remain = unsortedVector.back();

//   for (; it != unsortedVector.end() && (it + 1) != unsortedVector.end();
//        it += 2) {
//     pairA = *it;
//     pairB = *(it + 1);
//     if (pairA > pairB)
//       vectorPair.push_back(std::pair<int, int>(pairA, pairB));
//     else
//       vectorPair.push_back(std::pair<int, int>(pairB, pairA));
//   }

//   sortedVector = PmergeMe::vectorMergeInsertSort(vectorPair);
//   if (remain != -1)
//     PmergeMe::vectorInsertPairB(sortedVector, remain, 0,
//                                 sortedVector.size() - 1);
// }

// void PmergeMe::vectorInputNumbers(int ac, char** av) {
//   for (int i = 1; i < ac; i++) {
//     for (int j = 0;; j++) {
//       if (av[i][j] == '\0') break;

//       if (av[i][j] < 48 || av[i][j] > 57)
//         throw std::runtime_error("Error: not a number");
//     }

//     char* endptr;
//     double number = strtod(av[i], &endptr);
//     if (*endptr != '\0') throw std::runtime_error("Error: invalid number");
//     if (number < 0) throw std::runtime_error("Error: negative number");
//     if (number > INT_MAX) throw std::runtime_error("Error: INT_MAX
//     number");

//     int pushNumber = static_cast<int>(number);

//     std::vector<int>::iterator it =
//         std::find(unsortedVector.begin(), unsortedVector.end(),
//         pushNumber);
//     if (it != unsortedVector.end()) {
//       throw std::runtime_error("Error: duplicate number");
//     }
//     unsortedVector.push_back(number);
//   }
// }

// std::vector<int> PmergeMe::vectorMergeInsertSort(
//     std::vector<std::pair<int, int>> vectorPair) {
//   std::vector<int> insertVector;
//   std::vector<std::pair<int, int>>::iterator iter = vectorPair.begin();

//   // stop point
//   if (vectorPair.size() == 1) {
//     insertVector.push_back(iter->second);
//     insertVector.push_back(iter->first);
//     return insertVector;
//   }

//   // vectorPair 에서 더 divide
//   std::vector<std::pair<int, int>> nowPair;
//   int pairA, pairB;
//   int remain = -1;
//   for (; iter != vectorPair.end() && (iter + 1) != vectorPair.end();
//        iter += 2) {
//     // vectorPair 2개씩 추출해서 nowPair에 넣기
//     pairA = iter->first;
//     pairB = (iter + 1)->first;
//     if (pairA > pairB)
//       nowPair.push_back(std::pair<int, int>(pairA, pairB));
//     else
//       nowPair.push_back(std::pair<int, int>(pairB, pairA));
//   }
//   // remain
//   if (iter != vectorPair.end()) {
//     remain = iter->first;
//   }
//   // 재귀로 insertVector 받아오기
//   insertVector = vectorMergeInsertSort(nowPair);
//   if (remain != -1)
//     PmergeMe::vectorInsertPairB(insertVector, remain, 0,
//                                 insertVector.size() - 1);
//   // insertVector 안에 pairB 추가하기
//   std::vector<int> order = PmergeMe::vectorJacobsthal(insertVector);
//   std::vector<int>::iterator orderIter = order.begin();
//   bool frontFlag = true;
//   for (; orderIter != order.end(); orderIter++) {
//     pairA = *orderIter;

//     std::vector<std::pair<int, int>>::iterator pairIter =
//     vectorPair.begin(); for (; pairIter != vectorPair.end(); pairIter++) {
//       if (pairIter->first == pairA) {
//         pairB = pairIter->second;
//         break;
//       }
//     }
//     if (frontFlag) {
//       insertVector.insert(insertVector.begin(), pairB);
//       frontFlag = false;
//     } else {
//       std::vector<int>::iterator it =
//           std::find(insertVector.begin(), insertVector.end(), pairA);
//       int high = it - insertVector.begin();
//       PmergeMe::vectorInsertPairB(insertVector, pairB, 0, high - 1);
//     }
//   }
//   return insertVector;
// }

// std::vector<int> PmergeMe::vectorJacobsthal(std::vector<int> insertVector)
// {
//   std::vector<int> jacobsthalVector;
//   int count = insertVector.size();
//   int jacobsthalA = 1;
//   int jacobsthalB = 1;
//   int jacobsthalNum = -1;

//   jacobsthalVector.push_back(insertVector[0]);
//   while (jacobsthalNum != count) {
//     jacobsthalNum = jacobsthalA * 2 + jacobsthalB;
//     jacobsthalA = jacobsthalB;
//     jacobsthalB = jacobsthalNum;
//     if (jacobsthalNum >= count) jacobsthalNum = count;

//     for (int i = jacobsthalNum; jacobsthalA < i; i--) {
//       jacobsthalVector.push_back(insertVector[i - 1]);
//     }
//   }
//   return jacobsthalVector;
// }

// void PmergeMe::vectorInsertPairB(std::vector<int>& insertVector, int pairB,
//                                  int low, int high) {
//   // stop point
//   if (high == low) {
//     if (insertVector[high] > pairB)
//       insertVector.insert(insertVector.begin() + high, pairB);
//     else if (insertVector[high] < pairB)
//       insertVector.insert(insertVector.begin() + high + 1, pairB);
//     return;
//   }
//   int mid = (low + high) / 2;
//   if (pairB < insertVector[mid]) {
//     PmergeMe::vectorInsertPairB(insertVector, pairB, low, mid);
//   } else if (insertVector[mid] < pairB) {
//     if (mid == low)
//       PmergeMe::vectorInsertPairB(insertVector, pairB, mid + 1, high);
//     else
//       PmergeMe::vectorInsertPairB(insertVector, pairB, mid, high);
//   }
// }

// void PmergeMe::execute(int ac, char** av) {
//   std::clock_t start, end;

//   start = std::clock();
//   PmergeMe::executeDeque(ac, av);
//   end = std::clock();

//   dequeTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

//   start = std::clock();
//   PmergeMe::executeVector(ac, av);
//   end = std::clock();

//   vectorTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

//   PmergeMe::printResult();
// }

// void PmergeMe::printResult() {
//   if (dequePair.size() != sortedVector.size())
//     throw std::runtime_error("sorted check size error");

//   std::deque<int>::iterator iterDeque = sortedDeque.begin();
//   std::vector<int>::iterator iterVector = sortedVector.begin();
//   for (; iterDeque != sortedDeque.end() && iterVector !=
//   sortedVector.end();
//        iterDeque++, iterVector++) {
//     // TEST
//     // std::cout << *iterDeque << " " << *iterVector << std::endl;
//     // TEST
//     if (*iterDeque != *iterVector)
//       throw std::runtime_error("sorted check order error");
//   }

//   // PRINT
//   std::cout << "Before: ";
//   for (iterDeque = unsortedDeque.begin(); iterDeque != unsortedDeque.end();
//        iterDeque++) {
//     std::cout << *iterDeque << " ";
//   }
//   std::cout << std::endl;
//   std::cout << "After:  ";
//   for (iterDeque = sortedDeque.begin(); iterDeque != sortedDeque.end();
//        iterDeque++) {
//     std::cout << *iterDeque << " ";
//   }
//   std::cout << std::endl;
//   std::cout << "Time to process a range of " << sortedDeque.size()
//             << " elements with std::deque : " << dequeTime << " us"
//             << std::endl;
//   std::cout << "Time to process a range of " << sortedVector.size()
//             << " elements with std::vector : " << vectorTime << " us"
//             << std::endl;
// }