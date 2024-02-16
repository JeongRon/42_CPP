#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  double dequeTime;
  std::deque<int> unsortedDeque;
  std::deque<std::pair<int, std::deque<int> > > sortedDeque;
  std::deque<std::pair<int, std::deque<int> > > dequePair;
  double vectorTime;
  std::vector<int> unsortedVector;
  std::vector<std::pair<int, std::vector<int> > > sortedVector;
  std::vector<std::pair<int, std::vector<int> > > vectorPair;

  /* Deque */
  void executeDeque(int ac, char** av);
  void dequeInputNumbers(int ac, char** av);
  void dequeMergeInsertSort(int pairCount);
  void dequeInsertPair(std::pair<int, std::deque<int> > insertPair, int pairB,
                       int low, int high);
  std::deque<int> dequeJacobsthalIndex(int point);

  // /* Vector */
  void executeVector(int ac, char** av);
  void vectorInputNumbers(int ac, char** av);
  void vectorMergeInsertSort(int pairCount);
  void vectorInsertPair(std::pair<int, std::vector<int> > insertPair, int pairB,
                        int low, int high);
  std::vector<int> vectorJacobsthalIndex(int point);

  // /* Print */
  void printResult();

 public:
  /* OCF */
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  void execute(int ac, char** av);
  /* Member Function */
};

#endif