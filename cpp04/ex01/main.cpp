#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void leak_check() { system("leaks Brain"); }

int main() {
  // atexit(leak_check);

  // 과제 안에 있는 코드 구현
  std::cout << "----------------1-----------------" << std::endl;
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  std::cout << "----------------------------------" << std::endl;
  delete i;
  delete j;
  std::cout << "----------------------------------" << std::endl;

  // Animal 배열 리스트 생성
  std::cout << "----------------2-----------------" << std::endl;
  Animal* arr[10];
  for (int i = 0; i < 5; i++) {
    arr[i] = new Cat();
    arr[i + 5] = new Dog();
  }
  std::cout << "----------------------------------" << std::endl;
  for (int i = 0; i < 10; i++) delete arr[i];
  std::cout << "----------------------------------" << std::endl;

  std::cout << "----------------3-----------------" << std::endl;
  Cat* tmp1 = new Cat();
  std::string str;
  for (int i = 0; i < 10; i++) {
    str = "SET" + std::to_string(i);
    tmp1->getBrain()->setIdeas(i, str);
  }
  // Brain idea 값 바꾸기
  for (int i = 0; i < 20; i++)
    std::cout << tmp1->getBrain()->getIdeas(i) << std::endl;
  std::cout << "-----------tmp2 = tmp1-----------------" << std::endl;
  // Brain 깊은 복사 체크
  // (1) tmp2 -> tmp1을 복사
  Cat* tmp2 = new Cat(*tmp1);
  // (2) tmp2의 idea 값들을 변경
  for (int i = 0; i < 8; i++) {
    str = "DEEP CHECK" + std::to_string(i);
    tmp2->getBrain()->setIdeas(i, str);
  }
  // (3) idea 값들 확인 [얕은 복사면, tmp1도 변경 됨]
  std::cout << "--------DEEP CHECK (tmp1)-------------" << std::endl;
  for (int i = 0; i < 20; i++)
    std::cout << tmp1->getBrain()->getIdeas(i) << std::endl;
  std::cout << "--------DEEP CHECK (tmp2)-------------" << std::endl;
  for (int i = 0; i < 20; i++)
    std::cout << tmp2->getBrain()->getIdeas(i) << std::endl;
  std::cout << "----------------------------------" << std::endl;
  delete tmp1;
  delete tmp2;
  std::cout << "----------------------------------" << std::endl;

  return 0;
}