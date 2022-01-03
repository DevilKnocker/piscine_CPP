#include <iostream>
#include "PhoneBook.class.hpp"

int		how_many_contact(PhoneBook *phonebook)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < 8)
	{
		if (phonebook->contact[i].getFill())
			nb++;
		i++;
	}
	return (nb);
}

void	delete_contact(PhoneBook *phonebook)
{
	std::string buff;

	std::cout << "Specify what contact you zant to delete (1/2../7/8)" << std::endl;
	std::getline(std::cin, buff);
	(void)phonebook;
}

void	add_contact(PhoneBook *phonebook)
{
	std::string	buff;
	int i;

	if (how_many_contact(phonebook) >= 8)
	{
		std::cout << "Your phonebook is already full (8/8 contacts)" << std::endl << "Would you like to delete one (y/n) ?" << std::endl;
		std::getline(std::cin, buff);
		if (strcmp(buff.data(), "y"))
			delete_contact(phonebook);
		return ;
	}
	printf("%d\n", how_many_contact(phonebook));
	i = 0;
	while(std::getline(std::cin, buff) && i < 5)
	{
		switch (i)
		{
		case 0:
			phonebook->contact->first_name = buff;
			break;
		case 1:
			phonebook->contact->last_name = buff;
			break;
		case 2:
			phonebook->contact->nickname = buff;
			break;
		case 3:
			phonebook->contact->phone_number = buff;
			break;
		case 4:
			phonebook->contact->darkest_secret = buff;
			break;
		}
		i++;
		if (i == 5)
		{
			std::cout << "contact added" << std::endl;
			phonebook->contact[how_many_contact(phonebook)].setFill();
			return ;
		}
	}
	return ;
}

int main()
{
	int i;
    std::string buff;
    PhoneBook phonebook;

    while(std::getline(std::cin, buff))
    {
		i = 0;
        if (!strcmp(buff.data(), "EXIT A"))
            break;
        else if (!strcmp(buff.data(), "SEARCH"))
		{
			std::cout << phonebook.contact[0].first_name << phonebook.contact[0].last_name;
		}
        else if (!strcmp(buff.data(), "ADD"))
			add_contact(&phonebook);
    }

}