#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// 추상 클래스
class Animal {
 protected:
  std::string type;

 public:
  Animal();
  virtual ~Animal();
  Animal(const Animal& animal);
  Animal& operator=(Animal& animal);

  std::string getType() const;
  virtual void makeSound() const = 0;  // 순수 가상 함수
};

#endif