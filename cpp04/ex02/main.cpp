#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void leak_check() { system("leaks Brain"); }

int main() {
  // atexit(leak_check);

  std::cout << "----------------1-----------------" << std::endl;
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  // const Animal* k = new Animal();

  std::cout << "--------------SOUND---------------" << std::endl;
  i->makeSound();
  j->makeSound();
  std::cout << "-------------DELETE---------------" << std::endl;
  delete i;
  delete j;
  // delete k;
  std::cout << "----------------------------------" << std::endl;

  return 0;
}