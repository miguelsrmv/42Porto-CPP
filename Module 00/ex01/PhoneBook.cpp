#include "Contact.cpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

class PhoneBook
{
  private:
	Contact contact_list[8];
	int last_contact_index;

  public:
	PhoneBook ()
	{
		last_contact_index = -1;
		for (int i = 0; i < 8; i++)
			contact_list[i] = Contact ();
	}

	~PhoneBook () {}

	// Adds contact to list in case all fields are valid
	// Erases oldest contact in case list is full
	void
	add_contact ()
	{
		int contact_index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

		std::cout << "First name: " << std::endl;
		std::getline (std::cin, first_name);
		if (first_name == "" || !name_is_valid (first_name))
			{
				std::cout << "Error: Invalid first name!" << std::endl;
				return;
			}

		std::cout << "Last name: " << std::endl;
		std::getline (std::cin, last_name);
		if (last_name == "" || !name_is_valid (last_name))
			{
				std::cout << "Error: Invalid last name!" << std::endl;
				return;
			}

		std::cout << "Nickname: " << std::endl;
		std::getline (std::cin, nickname);
		if (nickname == "" || !name_is_valid (nickname))
			{
				std::cout << "Error: Invalid nickname!" << std::endl;
				return;
			}

		std::cout << "Phone number: " << std::endl;
		std::getline (std::cin, phone_number);
		if (phone_number == "" || !number_is_valid (phone_number))
			{
				std::cout << "Error: Invalid phone number!" << std::endl;
				return;
			}

		std::cout << "Darkest Secret: " << std::endl;
		std::getline (std::cin, darkest_secret);
		if (darkest_secret == "")
			{
				std::cout << "Error: Invalid darkest secret!" << std::endl;
				return;
			}

		last_contact_index++;
		contact_index = (last_contact_index) % 8;
		contact_list[contact_index] = Contact::set_contact (
			first_name, last_name, nickname, phone_number, darkest_secret);
		;
	}

	// Searches for contact at given index to print
	// Checks if index is valid and if contact exists
	void
	search_contact ()
	{
		Contact contact;
		std::string index;

		std::cout << "What index would you like to check? (0 to 7)"
				  << std::endl;
		std::getline (std::cin, index);

		if (index_is_invalid (index))
			return;

		contact = contact_list[atoi (index.c_str ())];
		if (contact_is_empty (contact))
			return;

		print_contact (contact, index);
	}

  private:
	// Prints contact information
	void
	print_contact (Contact contact, std::string index)
	{
		std::cout << std::setw (10) << std::right << index;
		std::cout << "|";
		std::cout << std::setw (10) << std::right
				  << truncate_string (contact.get_first_name ());
		std::cout << "|";
		std::cout << std::setw (10) << std::right
				  << truncate_string (contact.get_last_name ());
		std::cout << "|";
		std::cout << std::setw (10) << std::right
				  << truncate_string (contact.get_nickname ());
		std::cout << std::endl;
	}

	// Truncates string to maximum of length 10
	std::string
	truncate_string (std::string string)
	{
		if (string.length () > 10)
			return string.substr (0, 9) + '.';
		else
			return string;
	}

	// Check if contact exists
	bool
	contact_is_empty (Contact contact)
	{
		if (contact.get_first_name () == "")
			{
				std::cout << "Error: empty contact at given index!"
						  << std::endl;
				return true;
			}
		return false;
	}

	// Check if given index is invalid
	bool
	index_is_invalid (std::string index)
	{
		if (index.length () != 1 || index[0] < '0' || index[0] > '7')
			{
				std::cout << "Error: invalid index!" << std::endl;
				return true;
			}
		return false;
	}

	// Checks if name only has a-z and A-Z
	bool
	name_is_valid (std::string name)
	{
		for (int i = 0; name[i]; i++)
			{
				if (!isalpha (name[i]))
					return false;
			}
		return true;
	}

	// Checks if number only has 0-9
	bool
	number_is_valid (std::string number)
	{
		for (int i = 0; number[i]; i++)
			{
				if (!isdigit (number[i]))
					return false;
			}
		return true;
	}
};
