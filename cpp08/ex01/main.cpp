#include "Span.hpp"

int main() {
  try {
    std::vector<int> a;
    for (int i = 0; i < 10000; i++) a.push_back(i);

    Span sp = Span(10000);
    sp.addManyNumber<std::vector<int> >(a.begin(), a.end());

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

// int main(void) {
//   try {
//     Span sp = Span(5);

//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << std::endl;
//   }
//   return 0;
// }
