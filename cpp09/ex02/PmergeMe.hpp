#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  double dequeTime;
  std::deque<int> unsortedDeque;
  std::deque<int> sortedDeque;
  double vectorTime;
  std::vector<int> unsortedVector;
  std::vector<int> sortedVector;

  /* Deque */
  void executeDeque(int ac, char** av);
  void dequeInputNumbers(int ac, char** av);
  std::deque<int> dequeMergeInsertSort(
      std::deque<std::pair<int, int> > dequePair);
  std::deque<int> dequeJacobsthal(std::deque<int> insertDeque);
  void dequeInsertPairB(std::deque<int>& insertDeque, int pairB, int low,
                        int high);
  /* Vector */
  void executeVector(int ac, char** av);
  void vectorInputNumbers(int ac, char** av);
  std::vector<int> vectorMergeInsertSort(
      std::vector<std::pair<int, int> > vectorPair);
  std::vector<int> vectorJacobsthal(std::vector<int> insertVector);
  void vectorInsertPairB(std::vector<int>& insertVector, int pairB, int low,
                         int high);

  /* Print */
  void printResult();

 public:
  /* OCF */
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  /* Member Function */
  void execute(int ac, char** av);
};

#endif