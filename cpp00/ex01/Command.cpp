#include "PhoneBook.hpp"

void addContact(PhoneBook *phoneBook) {
    std::string contactInfo[5];
    
    std::cout << "(1) Input first name : ";
    std::cin >> contactInfo[0];
    std::cout << "(2) Input last name : ";
    std::cin >> contactInfo[1];
    std::cout << "(3) Input nick name : ";
    std::cin >> contactInfo[2];
    std::cout << "(4) Input phone number : ";
    std::cin >> contactInfo[3];
    std::cout << "(5) Input darkest secret : ";
    std::cin >> contactInfo[4];
    std::cout << "** COMPLETE ** " << std::endl;

    Contact temp(contactInfo);
    phoneBook->setContact(temp, phoneBook->getIndex());
    phoneBook->setIndex();
    phoneBook->setContactCount();
};

void searchContact(PhoneBook phoneBook) {
    int searchIndex;
    Contact tmp;

    printContactList(phoneBook);
        std::cout << "Search Index : ";
    if (!(std::cin >> searchIndex))
    {
        if (std::cin.eof()) {
            std::cout << '\n';
            return;
        }
        std::cout << "ERROR [Please Input Index Number]" << std::endl;
        std::cin.clear();
        return;
    }
    if (searchIndex < 0 || searchIndex > 7) {
        std::cout << "ERROR [Index Out Of Range] " << std::endl;
    } else if (phoneBook.getContactCount() <= searchIndex){
        std::cout << "ERROR [Index Out Of Range] " << std::endl;
    } else {
        tmp = phoneBook.getContact(searchIndex);
        tmp.printContactDetail();
    }
}

void printContactList(PhoneBook phoneBook) {
    Contact tmp;
    int     searchRange;

    std::cout << std::setw(10);
    std::cout << "index";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << "firstName";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << "lastName";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << "nickName";
    std::cout << "|" << std::endl;
    
    if (phoneBook.getIndex() != phoneBook.getContactCount())
        searchRange = 8;
    else
        searchRange = phoneBook.getIndex();
    for (int i = 0; i < searchRange; i++) {
        tmp = phoneBook.getContact(i);
        tmp.printContact(i);
    }
}