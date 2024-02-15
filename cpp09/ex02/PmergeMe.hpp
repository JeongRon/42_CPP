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
  void dequeInputNumbers(int ac, char** av);
  void dequeMergeInsertSort(int dequeCount);
  void dequeInsertPair(std::pair<int, std::deque<int> > insertPair, int pairB,
                       int low, int high);
  std::deque<int> dequeJacobsthalIndex(int point);

  // /* Vector */
  // void executeVector(int ac, char** av);
  // void vectorInputNumbers(int ac, char** av);
  // std::vector<int> vectorMergeInsertSort(
  //     std::vector<std::pair<int, int>> vectorPair);
  // std::vector<int> vectorJacobsthal(std::vector<int> insertVector);
  // void vectorInsertPairB(std::vector<int>& insertVector, int pairB, int low,
  //                        int high);

  // /* Print */
  // void printResult();

 public:
  /* OCF */
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  /* Member Function */
  void executeDeque(int ac, char** av);
  void execute(int ac, char** av);
};

#endif