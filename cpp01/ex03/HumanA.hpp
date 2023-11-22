#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
 private:
  std::string name;
  Weapon* weapon;  // 주소값만 들고 다니기

 public:
  HumanA(std::string name, Weapon& weapon);

  void attack();
};

#endif