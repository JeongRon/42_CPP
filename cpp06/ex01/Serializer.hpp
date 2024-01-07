#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

class Data;

class Serializer {
 private:
  /* OCF Block */
  Serializer();
  ~Serializer();
  Serializer(Serializer const& other);
  Serializer& operator=(Serializer const& other);

 public:
  /* static methods */
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif