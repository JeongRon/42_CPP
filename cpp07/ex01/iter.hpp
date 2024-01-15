#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, unsigned int arrLength, void (*f)(T&)) {
  for (unsigned int index = 0; index < arrLength; index++) {
    f(arr[index]);
  }
}

template <typename T>
void print(T& str) {
  std::cout << str << std::endl;
}

#endif