#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  name = "ScAvTrAp";
  hitPoint = 100;
  energyPoint = 50;
  attackDamage = 20;
  std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
  this->name = name;
  hitPoint = 100;
  energyPoint = 50;
  attackDamage = 20;
  std::cout << "ScavTrap Constructor " << name << " Called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& scavTrap) {
  name = scavTrap.name;
  hitPoint = scavTrap.hitPoint;
  energyPoint = scavTrap.energyPoint;
  attackDamage = scavTrap.attackDamage;
  std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
  name = scavTrap.name;
  hitPoint = scavTrap.hitPoint;
  energyPoint = scavTrap.energyPoint;
  attackDamage = scavTrap.attackDamage;
  std::cout << "ScavTrap Operator= Called" << std::endl;
  return (*this);
}

void ScavTrap::attack(std::string const& target) {
  std::cout << "---------------------" << std::endl;
  int flag = 0;
  if (hitPoint == 0) {
    std::cout << "ScavTrap " << name << " attack: There's No hitPoint !"
              << std::endl;
    flag = 1;
  }
  if (energyPoint == 0) {
    std::cout << "ScavTrap " << name << " attack: There's No energyPoint !"
              << std::endl;
    flag = 1;
  }
  if (flag == 0) {
    std::cout << "ScavTrap " << name << " attacks: " << target << ", causing "
              << attackDamage << " points of damage !" << std::endl;
    energyPoint--;
  }
  std::cout << "---------------------" << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "---------------------" << std::endl;
  int flag = 0;
  if (hitPoint == 0) {
    std::cout << "ScavTrap " << name
              << " Gatekeeper Mode: There's No hitPoint !" << std::endl;
    flag = 1;
  }
  if (energyPoint == 0) {
    std::cout << "ScavTrap " << name
              << " GateKeeper Mode: There's No energyPoint !" << std::endl;
    flag = 1;
  }
  if (flag == 0) {
    std::cout << "ScavTrap " << name << " GateKeeper Mode !" << std::endl;
  }
  std::cout << "---------------------" << std::endl;
}