#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  Zombie* tmp = new Zombie[N];  // 좀비 무리 선언

  for (int i = 0; i < N; i++) tmp[i].setZombieName(name);  // 각 좀비 이름 넣기

  return tmp;
}