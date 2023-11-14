#include "PhoneBook.hpp"

int main(void) {
    // std::cout << std::stoi("123");  // 버전 체크
    std::string command;
    PhoneBook phoneBook;

    while (true)
    {
        std::cout << "==================================================" << std::endl;
        std::cout << "Input Command [ADD or SEARCH or EXIT] : ";
        std::cin >> command;
        if (std::cin.eof())
        {
            std::cout << "ERROR [EOF]" << std::endl;
            break ;
        }
        if (command == "EXIT")
        {
            std::cout << "==================================================" << std::endl;
            break ;
        }
        else if (command == "ADD")
            addContact(&phoneBook);
        else if (command == "SEARCH")
            searchContact(phoneBook);
        else 
            std::cout << "ERROR [Invalid Command]" << std::endl;
    }
    return (0);
}