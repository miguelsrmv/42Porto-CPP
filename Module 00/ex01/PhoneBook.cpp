#include "PhoneBook.hpp"

PhoneBook::PhoneBook () : last_contact_index (-1) {}

PhoneBook::~PhoneBook () {}

// Adds contact to list
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
// Checks if index is valid and, if so, if contact exists (ie: it's valid)
void
PhoneBook::search_contact ()
{
	Contact contact;
	std::string index;

	print_table ();

	std::cout << "What index would you like to check? (0 to 7)" << std::endl;
	std::getline (std::cin, index);

	if (index_is_invalid (index))
		return;

	contact = contact_list[atoi (index.c_str ())];
	if (!contact.is_valid ())
		{
			std::cout << "Error: empty slot!" << std::endl;
			return;
		}

	std::cout << "First Name: " << contact.get_first_name () << std::endl;
	std::cout << "Last Name: " << contact.get_last_name () << std::endl;
	std::cout << "Nickname: " << contact.get_nickname () << std::endl;
	std::cout << "Phonenumber: " << contact.get_phone_number () << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret ()
			  << std::endl
			  << std::endl;
}

void
PhoneBook::print_table ()
{
	std::cout << std::setw (10) << std::right << "Index";
	std::cout << "|";
	std::cout << std::setw (10) << std::right << "First Name";
	std::cout << "|";
	std::cout << std::setw (10) << std::right << "Last Name";
	std::cout << "|";
	std::cout << std::setw (10) << std::right << "Nickname";
	std::cout << std::endl;

	int index = 0;
	while (contact_list[index].is_valid ())
		{
			print_contact (contact_list[index], index);
			index++;
		}

	std::cout << std::endl;
}

// Prints contact information
// Format [Index|First name|Last name|Nickname]
void
PhoneBook::print_contact (const Contact &contact, const int index)
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

// Truncates string to maximum of length 10, puts '.' on 10th element
std::string
PhoneBook::truncate_string (const std::string &string)
{
	if (string.length () > 10)
		return string.substr (0, 9) + '.';
	else
		return string;
}

// Check if given index is invalid (within 0 and 7)
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
