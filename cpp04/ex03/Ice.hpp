#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

// 구체 클래스
class Ice : public AMateria {
 public:
  Ice();
  ~Ice();
  Ice(const Ice& cure);
  Ice& operator=(Ice& cure);

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif