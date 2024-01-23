#include <deque>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::cout << "---------------Vector Test-------------------" << std::endl;
  std::vector<int> v;
  std::vector<int>::iterator it;
  for (int i = 0; i < 5; i++) v.push_back(i);

  try {
    it = easyfind(v, 5);  // error
    std::cout << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------" << std::endl;

  try {
    for (int i = 0; i < 5; i++) {
      it = easyfind(v, i);  // Not error
      std::cout << *it << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "---------------Deuque Test-------------------" << std::endl;
  std::deque<int> dq;
  std::deque<int>::iterator itt;
  for (int i = 0; i < 5; i++) dq.push_back(i);

  try {
    itt = easyfind(dq, 5);  // error
    std::cout << *itt << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------" << std::endl;

  try {
    itt = easyfind(dq, 1);  // Not error
    std::cout << *itt << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}