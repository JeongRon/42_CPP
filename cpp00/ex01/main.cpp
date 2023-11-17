#include "PhoneBook.hpp"

int main(void) {
  std::string command;
  PhoneBook phoneBook;

  while (true) {
    std::cout << "=================================================="
              << std::endl;
    std::cout << "Input Command [ADD or SEARCH or EXIT] : ";
    std::cin >> command;
    if (std::cin.eof()) {
      std::cout << "ERROR [EOF]" << std::endl;
      break;
    }
    if (command == "EXIT") {
      std::cout << "=================================================="
                << std::endl;
      break;
    } else if (command == "ADD")
      phoneBook.addContact();
    else if (command == "SEARCH")
      phoneBook.searchContact();
    else
      std::cout << "ERROR [Invalid Command]" << std::endl;
  }
  return (0);
}