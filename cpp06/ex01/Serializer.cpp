#include "Serializer.hpp"

#include "Data.hpp"

/* OCF Block */
Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const& other) { (void)other; }

Serializer& Serializer::operator=(Serializer const& other) {
  (void)other;
  return (*this);
}

/* static methods */
uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}