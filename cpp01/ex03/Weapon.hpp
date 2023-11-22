#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
 private:
  std::string type;

 public:
  Weapon(std::string type);

  const std::string& getType() const;
  // 앞 const는 리턴된 자료형의 값을 변경 못하게 하는 역할
  // 뒤 const는 함수 안에서 type 변수의 값을 변경 못하게 하는 역할
  void setType(std::string type);
};

#endif