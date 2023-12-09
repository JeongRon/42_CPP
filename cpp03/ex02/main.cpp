#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  FragTrap a("A");
  FragTrap b("B");

  a.attack("B");
  b.takeDamage(5);
  b.beRepaired(3);

  b.attack("A");
  a.takeDamage(10);
  a.beRepaired(10);

  // virtual 없을 시, 잘못된 예시 추가하기
  ClapTrap *c = &b;  // 업캐스팅 (파생 클래스를 -> 기반 클래스로 캐스팅)
  c->attack("B");

  return (0);
}