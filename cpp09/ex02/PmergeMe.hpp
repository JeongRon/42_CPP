#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <utility>

class PmergeMe {
 private:
  std::deque<int> unsortedContainer;

 public:
  /* OCF */
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  /* Member Function */
  void executeDeque(int ac, char** av);
  void dequeInputNumbers(int ac, char** av);
  std::deque<int> dequeMergeInsertSort(
      std::deque<std::pair<int, int> > dequePair);
  std::deque<int> dequeJacobsthal(std::deque<int> insertDeque);
};

#endif