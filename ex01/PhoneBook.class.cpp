#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(void) {

}

PhoneBook::~PhoneBook(void) {


}

bool	PhoneBook::delete_contact(void)
{
	std::string buff;
	int	nb;

	std::cout << "Your phonebook is already full (8/8 contacts)" << std::endl << "Would you like to delete one (y/n) ?" << std::endl;
	std::getline(std::cin, buff);
	if (strcmp(buff.data(), "y"))
		return (0);
	std::cout << "Specify what contact you want to delete (0/2.../6/7)" << std::endl;
	std::getline(std::cin, buff);
	nb = atoi(buff.c_str());
	if (nb >= 0 && nb <= 7)
	{
		this->contact[nb].setFill();
		std::cout << "Contact " << nb << " successfully deleted" << std::endl;
		return (1);
	}
	return (0);
}

int		PhoneBook::how_many_contact() const
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < 8)
	{
		if (this->contact[i].getFill())
			nb++;
		i++;
	}
	return (nb);
}

void	PhoneBook::add_contact()
{
	std::string	buff;
	std::string msg;
	int nb;
	int i;
	bool	valid;

	if (this->how_many_contact() == 8)
		if (this->delete_contact() == 0)
		{
			std::cout << "No contact deleted, command canceled" << std::endl;
			return ;
		}
	nb = this->how_many_contact();
	i = 0;
	msg = "First name : ";
	while(std::cout << msg && std::getline(std::cin, buff))
	{
		valid = 1;
		if (i == 3 && (strlen(buff.c_str()) != 10 || buff.find_first_not_of("0123456789") != buff.npos))
		{
			std::cout << "Phone number must be 10 digits" << std::endl;
			valid = 0;
		}
		else if ((i == 0 || i == 1 || i == 2) && buff.find_first_not_of("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm") != buff.npos && buff.find_first_not_of("-'") == buff.npos)
		{
			std::cout << "Did you try to fool me ?" << std::endl;
			valid = 0;
		}
		else if (strlen(buff.c_str()) > 30)
		{
			std::cout << "As you press the enter key, you hear the wind blow and the time stops." << std::endl << 
			"-\"You tried something you should not\" says a voice in your head." << std::endl << 
			"-\"I created that phonebook in such a maneer that it sucks, so you can't type anything longer than 30 characters\"" << std::endl <<
			"You come back to reality and feel guilty of trying this.\nTry something else." << std::endl;
			valid = 0;
		}
		else if ((i == 0 || i == 1 || i == 2) && buff.find_first_not_of("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm'-") != buff.npos)
		{
			std::cout << "No one has such a character in its name.. How pityful." << std::endl;
			valid = 0;
		}
		if (valid == 1)
			switch (i)
			{
			case 0:
				this->contact[nb].first_name = buff;
				msg = "Last name : ";
				break;
			case 1:
				this->contact[nb].last_name = buff;
				msg = "Nickname : ";
				break;
			case 2:
				this->contact[nb].nickname = buff;
				msg = "Phone number : ";
				break;
			case 3:
				this->contact[nb].phone_number = buff;
				msg = "Darkest secret : ";
				break;
			case 4:
				this->contact[nb].darkest_secret = buff;
				break;
			}
		if (valid == 1)
			i++;
		if (i == 5)
		{
			std::cout << "contact added" << std::endl;
			this->contact[nb].setFill();
			return ;
		}
	}
	return ;
}

void	PhoneBook::print_contacts() const
{
	std::string buff;
	int i;
	int j;
	bool over[3];
	bool index;
	std::stringstream str[3];
	char	str2[10];

	i = 0;
	std::cout << std::endl;
	std::cout << "*----------*----------*----------*----------*" << std::endl;
	std::cout << "|     INDEX|FIRST_NAME| LAST_NAME|  NICKNAME|" << std::endl;
	std::cout << "*----------*----------*----------*----------*" << std::endl;
	while(i < 8 && this->contact[i].getFill())
	{
		index = 1;
		j = 0;
		str[0] << this->contact[i].first_name;
		str[1].str(this->contact[i].last_name);
		str[2].str(this->contact[i].nickname);
		str[0].str(this->contact[i].first_name);
		over[0] = 0;
		over[1] = 0;
		over[2] = 0;
		while ((over[0] != 1 || over[1] != 1 || over[2] != 1) || j != 0)
		{
			if (index)
			{
				std::cout << "|         " << i << "|";
				index = 0;
			}
			else if (j == 0)
				std::cout << "|          |";
			if (str[j].str().length() <= 10 && over[j] == 0)
			{
				std::cout << std::setw(10) << str[j].str() << "|";
				over[j] = 1;
			}
			else if (over[j] == 0 && str[j] >> std::setw(10) >> str2)
				std::cout << std::setw(9) << str2 << ".|";
			else
			{
				over[j] = 1;
				std::cout << "          |";
			}
			j++;
			if (j == 3)
			{
				j = 0;
				std::cout << std::endl;
			}
		}
		std::cout << "*----------*----------*----------*----------*" << std::endl;
		i++;
	}
	std::cout << std::endl << "Index to browse : ";
	while (std::getline(std::cin, buff))
	{
		i = atoi(buff.c_str());
		if (this->contact[i].getFill())
		{
			std::cout << std::endl << "---------------------------------------------" << std::endl;
			std::cout << "First name : " << this->contact[i].first_name << std::endl << "Last name : " <<
			this->contact[i].last_name << std::endl << "Nickname : " << this->contact[i].nickname <<
			std::endl << "Phone number : " << this->contact[i].phone_number << std::endl
			<< "Darkest secret : " << this->contact[i].darkest_secret << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			break;
		}
		else
			std::cout << "This is not a correct index, please choose a correct one" << std::endl;
	}
}
