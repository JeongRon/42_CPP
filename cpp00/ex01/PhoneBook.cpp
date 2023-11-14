#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
    contactsCount = 0;
    for (int i = 0; i < 8; i++)
        contacts[i] = Contact();
};

int PhoneBook::getIndex() {
    return (this->index);
}

int PhoneBook::getContactCount() {
    return (this->contactsCount);
}

Contact PhoneBook::getContact(int index) {
    return (this->contacts[index]);
}

void PhoneBook::setIndex() {
    this->index = (this->index + 1) % 8;
}

void PhoneBook::setContactCount() {
    this->contactsCount += 1;
}

void PhoneBook::setContact(Contact contact, int index) {
    this->contacts[index] = contact;
}

