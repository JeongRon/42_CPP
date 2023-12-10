#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void leak_check() { system("leaks Animal"); }

int main() {
  // atexit(leak_check);
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  j->makeSound();
  i->makeSound();  // will output the cat sound!
  meta->makeSound();

  std::cout << "---------------" << std::endl;

  const WrongAnimal* tmp1 = new WrongAnimal();
  const WrongAnimal* tmp2 = new WrongCat();
  std::cout << tmp1->getType() << " " << std::endl;
  std::cout << tmp2->getType() << " " << std::endl;
  tmp1->makeSound();
  tmp2->makeSound();  // will output the cat sound!

  std::cout << "---------------" << std::endl;
  delete meta;
  delete i;
  delete j;
  delete tmp1;
  delete tmp2;
  return 0;
}