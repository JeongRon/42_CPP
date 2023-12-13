#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  ~WrongCat();
  WrongCat(const WrongCat& wrongcat);
  WrongCat& operator=(WrongCat& wrongcat);

  void makeSound() const;
};

#endif