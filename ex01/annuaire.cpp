#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.class.hpp"

int main()
{
	int i;
    std::string buff;
    PhoneBook phonebook;

    while(std::cout << std::endl << "Welcome to PhoneBook v1.0" << std::endl <<
	"type EXIT/SEARCH/ADD" << std::endl << std::endl && 
	std::getline(std::cin, buff))
    {
		i = 0;
		std::cout << " T BO <3" << std::endl; 
        if (!strcmp(buff.data(), "EXIT"))
            break;	
        else if (!strcmp(buff.data(), "SEARCH"))
		{
			if (phonebook.how_many_contact())
				phonebook.print_contacts();
			else
				std::cout << "You have not registered any contact yet" << std::endl;
		}
        else if (!strcmp(buff.data(), "ADD"))
			phonebook.add_contact();
    }

}