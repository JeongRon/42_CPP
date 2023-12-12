#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void leak_check() { system("leaks Recap"); }

int main() {
  atexit(leak_check);

  std::cout << "----------------1-----------------" << std::endl;
  IMateriaSource* src = new MateriaSource();
  std::cout << "----------------------------------" << std::endl;
  src->learnMateria(new Ice());
  std::cout << "----------------------------------" << std::endl;
  src->learnMateria(new Ice());
  std::cout << "----------------------------------" << std::endl;
  ICharacter* me = new Character("me");
  std::cout << "----------------------------------" << std::endl;
  AMateria* tmp;
  std::cout << "----------------------------------" << std::endl;
  tmp = src->createMateria("ice");
  std::cout << "----------------------------------" << std::endl;
  me->equip(tmp);
  std::cout << "----------------------------------" << std::endl;
  tmp = src->createMateria("cure");
  std::cout << "----------------------------------" << std::endl;
  me->equip(tmp);
  std::cout << "----------------------------------" << std::endl;
  ICharacter* bob = new Character("bob");
  std::cout << "----------------------------------" << std::endl;
  me->use(0, *bob);
  std::cout << "----------------------------------" << std::endl;
  me->use(1, *bob);
  std::cout << "----------------------------------" << std::endl;

  delete bob;
  delete me;
  delete src;
  std::cout << "----------------------------------" << std::endl;

  return 0;
}