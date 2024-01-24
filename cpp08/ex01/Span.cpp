#include "Span.hpp"

/* Block */
Span::Span() {}

/* public */
Span::Span(unsigned int N) { spanVector.reserve(N); }

Span::~Span() {}

Span::Span(const Span& other) { this->spanVector = other.spanVector; }

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    this->spanVector = other.spanVector;
  }
  return *this;
}

/* Member Function */
void Span::addNumber(unsigned int N) {
  if (spanVector.capacity() == spanVector.size())
    throw std::runtime_error("The container is full of numbers.");
  spanVector.push_back(N);
}

unsigned int Span::shortestSpan() {
  if (spanVector.size() <= 1)
    throw std::runtime_error("There are not enough numbers in the container.");

  std::sort(spanVector.begin(), spanVector.end());

  unsigned int shortestValue = std::numeric_limits<unsigned int>::max();

  for (std::vector<unsigned int>::iterator now = spanVector.begin();
       now != spanVector.end(); now++) {
    std::vector<unsigned int>::iterator next = now + 1;
    if (next != spanVector.end()) {
      unsigned int value = *next - *now;
      if (shortestValue > value) shortestValue = value;
    }
  }
  return shortestValue;
}

unsigned int Span::longestSpan() {
  if (spanVector.size() <= 1)
    throw std::runtime_error("There are not enough numbers in the container.");

  std::sort(spanVector.begin(), spanVector.end());

  unsigned int minValue = spanVector.front();
  unsigned int maxValue = spanVector.back();

  return maxValue - minValue;
}