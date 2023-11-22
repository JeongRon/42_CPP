#include "HumanA.hpp"
#include "HumanB.hpp"

// Weapon 객체 생성
// HumanA 객체 안에 생성한 Weapon 객체 넣기
// Weapon 객체의 속성 변경 시, HumanA의 Weapon 객체도 변경이 되는지!
int main() {
  {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");

    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}