#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include <string>

class PhoneBook {

public:

	class Contact {

	public:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

		Contact(void);
		~Contact(void);

		void setFill(void);
		int getFill(void) const;

	private:
		bool _Fill;
	};

	Contact contact[8];

	PhoneBook(void);
	~PhoneBook(void);

private:

};

#endif