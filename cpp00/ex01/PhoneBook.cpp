#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
  index = 0;
  contactsCount = 0;
  for (int i = 0; i < 8; i++) contacts[i] = Contact();
};

int PhoneBook::getIndex() { return (this->index); }

int PhoneBook::getContactCount() { return (this->contactsCount); }

Contact PhoneBook::getContact(int index) { return (this->contacts[index]); }

void PhoneBook::plusIndex() { this->index = (this->index + 1) % 8; }

void PhoneBook::plusContactCount() { this->contactsCount += 1; }

void PhoneBook::setContact(Contact contact, int index) {
  this->contacts[index] = contact;
}

void PhoneBook::addContact() {
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
  setContact(temp, this->getIndex());
  plusIndex();
  plusContactCount();
};

void PhoneBook::searchContact() {
  int searchIndex;
  Contact tmp;

  printContactList();
  std::cout << "Search Index : ";
  if (!(std::cin >> searchIndex)) {
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
  } else if (this->getContactCount() <= searchIndex) {
    std::cout << "ERROR [Index Out Of Range] " << std::endl;
  } else {
    tmp = this->getContact(searchIndex);
    tmp.printContactDetail();
  }
}

void PhoneBook::printContactList() {
  Contact tmp;
  int searchRange;

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

  if (this->getIndex() != this->getContactCount())
    searchRange = 8;
  else
    searchRange = this->getIndex();
  for (int i = 0; i < searchRange; i++) {
    tmp = this->getContact(i);
    tmp.printContact(i);
  }
}