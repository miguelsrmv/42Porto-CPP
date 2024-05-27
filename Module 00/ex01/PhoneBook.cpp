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
		Contact new_contact;
		int contact_index;

		new_contact = Contact::create_contact ();

		if (!contact_is_empty (new_contact))
			{
				last_contact_index++;
				contact_index = (last_contact_index) % 8;
				contact_list[contact_index] = new_contact;
			}
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
};
