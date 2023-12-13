#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// void leak_check() { system("leaks Recap"); }

int main() {
  // atexit(leak_check);

  std::cout << "----------------1-----------------" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << "----------------------------------" << std::endl;

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  // std::cout << "------------************----------" << std::endl;
  // me->unequip(1);
  // delete tmp;
  // std::cout << "------------************----------" << std::endl;

  std::cout << "----------------------------------" << std::endl;
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << "----------------------------------" << std::endl;

  delete bob;
  delete me;
  delete src;
  std::cout << "----------------------------------" << std::endl;

  return 0;
}