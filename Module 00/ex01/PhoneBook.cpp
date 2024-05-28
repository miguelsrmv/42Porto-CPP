#include "PhoneBook.hpp"

PhoneBook::PhoneBook () : last_contact_index (-1)
{
	for (int i = 0; i < 8; i++)
		contact_list[i] = Contact ();
}

PhoneBook::~PhoneBook () {}

// Adds contact o list
void
PhoneBook::add_contact ()
{
	Contact new_contact;

	new_contact = Contact::create_contact ();

	if (new_contact.is_valid ())
		{
			last_contact_index++;
			contact_list[(last_contact_index) % 8] = new_contact;
		}
}

// Searches for contact at given index to print
// Checks if index is valid and if contact exists
void
PhoneBook::search_contact ()
{
	Contact contact;
	std::string index;

	std::cout << "What index would you like to check? (0 to 7)" << std::endl;
	std::getline (std::cin, index);

	if (index_is_invalid (index))
		return;

	contact = contact_list[atoi (index.c_str ())];
	if (!contact.is_valid ())
		{
			std::cout << "Empty slot!" << std::endl;
			return;
		}

	print_contact (contact, index);
}

// Prints contact information
void
PhoneBook::print_contact (const Contact &contact, const std::string &index)
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
PhoneBook::truncate_string (const std::string &string)
{
	if (string.length () > 10)
		return string.substr (0, 9) + '.';
	else
		return string;
}

// Check if given index is invalid
bool
PhoneBook::index_is_invalid (const std::string &index)
{
	if (index.length () != 1 || index[0] < '0' || index[0] > '7')
		{
			std::cout << "Error: invalid index!" << std::endl;
			return true;
		}
	return false;
}
