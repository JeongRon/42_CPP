#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>

class PmergeMe {
 private:
  std::map<int, int> pairMap;
  int remain;

 public:
  /* OCF */
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  /* Member Function */
  void inputNumbers(int ac, char** av);  // unorderedNumbers
  void mergeInsertSortDeque();           // merge_insert_sort deque
  //   void mergeInsertSortQueue();           // merge_insert_sort queue
};

#endif