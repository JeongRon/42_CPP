#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Span {
 private:
  std::vector<unsigned int> spanVector;

  /* Block */
  Span();

 public:
  Span(unsigned int N);
  ~Span();
  Span(const Span& other);
  Span& operator=(const Span& other);

  /* Member Function */
  void addNumber(unsigned int N);

  unsigned int shortestSpan();
  unsigned int longestSpan();

  template <typename T>
  void addManyNumber(typename T::iterator start, typename T::iterator end) {
    if (end < start) throw std::runtime_error("hhh");
    size_t sub = end - start;
    if (spanVector.capacity() < spanVector.size() + sub)
      throw std::runtime_error("The container is full of numbers.");

    for (typename T::iterator it = start; it != end; it++) {
      spanVector.push_back(*it);
    }
  }
};

#endif