#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  name = "Empty";
  hitPoint = 10;
  energyPoint = 10;
  attackDamage = 0;
  std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  this->name = name;
  hitPoint = 10;
  energyPoint = 10;
  attackDamage = 0;
  std::cout << "ClapTrap Constructor " << name << " Called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& clapTrap) {
  name = clapTrap.name;
  hitPoint = clapTrap.hitPoint;
  energyPoint = clapTrap.energyPoint;
  attackDamage = clapTrap.attackDamage;
  std::cout << "ClapTrap Copy Constructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
  name = clapTrap.name;
  hitPoint = clapTrap.hitPoint;
  energyPoint = clapTrap.energyPoint;
  attackDamage = clapTrap.attackDamage;
  std::cout << "ClapTrap Operator= Called" << std::endl;
  return (*this);
}

void ClapTrap::attack(const std::string& target) {
  std::cout << "---------------------" << std::endl;
  int flag = 0;
  if (hitPoint == 0) {
    std::cout << "ClapTrap " << name << " attack: There's No hitPoint !"
              << std::endl;
    flag = 1;
  }
  if (energyPoint == 0) {
    std::cout << "ClapTrap " << name << " attack: There's No energyPoint !"
              << std::endl;
    flag = 1;
  }
  if (flag == 0) {
    std::cout << "ClapTrap " << name << " attacks: " << target << ", causing "
              << attackDamage << " points of damage !" << std::endl;
    energyPoint--;
  }
  std::cout << "---------------------" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "---------------------" << std::endl;
  hitPoint -= amount;
  if (hitPoint < 0) hitPoint = 0;
  std::cout << "ClapTrap " << name << " take " << amount << " damage !"
            << std::endl;
  std::cout << "ClapTrap " << name << " hitPoint: " << hitPoint << std::endl;
  std::cout << "---------------------" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "---------------------" << std::endl;
  int flag = 0;
  if (hitPoint == 0) {
    std::cout << "ClapTrap " << name << " repair: There's No hitPoint !"
              << std::endl;
    flag = 1;
  }
  if (energyPoint == 0) {
    std::cout << "ClapTrap " << name << " repair: There's No energyPoint !"
              << std::endl;
    flag = 1;
  }
  if (flag == 0) {
    hitPoint += amount;
    std::cout << "ClapTrap " << name << " be Reaired !" << std::endl;
    energyPoint--;
    std::cout << "ClapTrap " << name << " hitPoint: " << hitPoint << std::endl;
  }
  std::cout << "---------------------" << std::endl;
}