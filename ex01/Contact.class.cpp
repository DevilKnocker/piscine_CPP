#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::Contact::Contact(void) : _Fill(0){

    std::cout << "Constructor called" << std::endl;
}

PhoneBook::Contact::~Contact(void) {

    std::cout << "Destructor called" << std::endl;

}

void PhoneBook::Contact::setFill(void) {

    PhoneBook::Contact::_Fill = 1;
}
int PhoneBook::Contact::getFill(void) const {

    return (Contact::_Fill);
}