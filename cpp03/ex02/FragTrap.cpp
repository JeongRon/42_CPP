#include "FragTrap.hpp"

FragTrap::FragTrap() {
  name = "FrAgTrAp";
  hitPoint = 100;
  energyPoint = 100;
  attackDamage = 30;
  std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
  this->name = name;
  hitPoint = 100;
  energyPoint = 100;
  attackDamage = 30;
  std::cout << "FragTrap Constructor " << name << " Called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap& fragTrap) : ClapTrap(fragTrap) {
  name = fragTrap.name;
  hitPoint = fragTrap.hitPoint;
  energyPoint = fragTrap.energyPoint;
  attackDamage = fragTrap.attackDamage;
  std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
  name = fragTrap.name;
  hitPoint = fragTrap.hitPoint;
  energyPoint = fragTrap.energyPoint;
  attackDamage = fragTrap.attackDamage;
  std::cout << "FragTrap Operator= Called" << std::endl;
  return (*this);
}

void FragTrap::highFivesGuys(void) {
  std::cout << "---------------------" << std::endl;
  int flag = 0;
  if (hitPoint == 0) {
    std::cout << "FragTrap " << name << " HighFivesGuys: There's No hitPoint !"
              << std::endl;
    flag = 1;
  }
  if (energyPoint == 0) {
    std::cout << "FragTrap " << name
              << " HighFivesGuys: There's No energyPoint !" << std::endl;
    flag = 1;
  }
  if (flag == 0) {
    std::cout << "FragTrap " << name << " HighFivesGuys !" << std::endl;
  }
  std::cout << "---------------------" << std::endl;
}