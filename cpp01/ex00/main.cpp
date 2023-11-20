#include "Zombie.hpp"

int main(void) {
  // (1) newZombie 생성
  Zombie* one = newZombie("first");
  Zombie* two = newZombie("second");
  Zombie* three = newZombie("third");
  one->announce();
  two->announce();
  three->announce();
  delete one;
  delete two;
  delete three;
  std::cout << "---------------------" << std::endl;
  // (2) randomChump 생성
  randomChump("AAA");
  randomChump("BBB");
  randomChump("CCC");
  std::cout << "---------------------" << std::endl;
  Zombie lee("lee");
  Zombie jeong("jeong");
  Zombie ron("ron");
  lee.announce();
  jeong.announce();
  ron.announce();
  return (0);
}