#include "Zombie.hpp"

int main(void) {
  int N = 5;
  Zombie* zombie = zombieHorde(N, "HORDE");  // 좀비 무리 생성

  for (int i = 0; i < N; i++) {
    zombie[i].announce();  // 각 좀비 announce 호출
  }

  delete[] zombie;  // 좀비 무리 삭제

  return (0);
}