#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
 private:
  std::string name;
  Weapon& weapon;  // 레퍼런스 선언

 public:
  HumanA(std::string name, Weapon& weapon);

  void attack();
};

#endif