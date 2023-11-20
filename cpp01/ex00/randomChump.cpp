#include "Zombie.hpp"

void randomChump(std::string name) {
  // // (1) heap
  // Zombie* zombie = new Zombie(name);
  // zombie->announce();
  // delete zombie;

  // (2) stack
  Zombie tmp(name);
  tmp.announce();
}