#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::Contact::Contact(void) : _Fill(0){

}

PhoneBook::Contact::~Contact(void) {


}

void PhoneBook::Contact::setFill(void) {

	if (PhoneBook::Contact::_Fill == 0)
    	PhoneBook::Contact::_Fill = 1;
	else
    	PhoneBook::Contact::_Fill = 0;
}
int PhoneBook::Contact::getFill(void) const {

    return (Contact::_Fill);
}