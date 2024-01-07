#include "Data.hpp"

Data::Data(int val) : value(val) {}

/* OCF */
Data::Data() : value(0) {}

Data::~Data() {}

Data::Data(Data const& other) { this->value = other.value; }

Data& Data::operator=(Data const& other) {
  this->value = other.value;
  return (*this);
}

/* Getter */
int Data::getValue() { return value; }