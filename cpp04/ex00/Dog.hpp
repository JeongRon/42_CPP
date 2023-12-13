#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  ~Dog();
  Dog(const Dog& dog);
  Dog& operator=(Dog& dog);

  void makeSound() const;
};

#endif