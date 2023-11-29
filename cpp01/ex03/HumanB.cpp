#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
  this->name = name;
  this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void HumanB::attack() {
  if (!this->weapon)
    std::cout << this->name << " No Weapon" << std::endl;
  else
    std::cout << this->name << " attacks with their " << this->weapon->getType()
              << std::endl;
}
