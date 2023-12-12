#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

// 구체 클래스
class Cure : public AMateria {
 public:
  Cure();
  ~Cure();
  Cure(const Cure& cure);
  Cure& operator=(Cure& cure);

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif