#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
 private:
  T* array;
  unsigned int arraySize;

 public:
  Array() : array(NULL), arraySize(0) {}

  Array(unsigned int n) : array(NULL), arraySize(n) {
    if (this->arraySize != 0) {
      this->array = new T[this->arraySize];
    }
  }

  ~Array() {
    if (this->array) delete[] this->array;
  }

  Array(const Array& other) : array(NULL), arraySize(other.size()) {
    if (this->arraySize != 0) {
      this->array = new T[this->arraySize];

      for (unsigned int index = 0; index < this->arraySize; index++) {
        this->array[index] = other[index];
      }
    }
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      if (this->array) {
        delete[] this->array;
        this->array = NULL;
      }

      this->arraySize = other.size();

      if (this->arraySize != 0) {
        this->array = new T[this->arraySize];
      }

      for (unsigned int index = 0; index < this->arraySize; index++) {
        this->array[index] = other[index];
      }
    }
    return *this;
  }

  T& operator[](unsigned int index) {
    if (index < 0 || index > this->arraySize - 1) throw OutOfRange();
    return this->array[index];
  }

  const T& operator[](unsigned int index) const {
    if (index < 0 || index > this->arraySize - 1) throw OutOfRange();
    return this->array[index];
  }

  unsigned int size() const { return this->arraySize; }

  class OutOfRange : public std::exception {
    const char* what() const throw() { return "Index Error: Out Of Range"; }
  };
};

#endif