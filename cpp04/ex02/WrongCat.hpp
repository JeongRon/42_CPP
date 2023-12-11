#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  ~WrongCat();
  WrongCat(const WrongCat& cat);
  WrongCat& operator=(WrongCat& cat);

  void makeSound() const;
};

#endif