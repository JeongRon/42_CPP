#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie() {
  std::cout << this->name << ": "
            << "Delete..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->name << ": "
            << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string name) { this->name = name; }