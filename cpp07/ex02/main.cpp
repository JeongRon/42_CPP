#include "Array.hpp"

int main() {
  try {
    // 정수형 배열 템플릿 인스턴스화
    Array<int> intArray(5);

    // 배열에 값 할당
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      intArray[i] = i * 2;
    }

    // 배열 값 출력
    std::cout << "Array values: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // 특정 인덱스의 값 변경
    unsigned int indexToModify = 2;
    intArray[indexToModify] = 42;

    // 변경된 배열 값 출력
    std::cout << "Modified array values: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

// #define MAX_VAL 750
// int main(int, char**) {
//   Array<int> numbers(MAX_VAL);
//   int* mirror = new int[MAX_VAL];
//   srand(time(NULL));
//   for (int i = 0; i < MAX_VAL; i++) {
//     const int value = rand();
//     numbers[i] = value;
//     mirror[i] = value;
//   }
//   // SCOPE
//   {
//     Array<int> tmp = numbers;
//     Array<int> test(tmp);
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//   try {
//     numbers[-2] = 0;
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }
//   try {
//     numbers[MAX_VAL] = 0;
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     numbers[i] = rand();
//   }
//   delete[] mirror;  //
//   return 0;
// }