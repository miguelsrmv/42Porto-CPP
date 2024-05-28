#include "Contact.hpp"

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret(""), valid_contact(false) {}
Contact::~Contact() {}

// Getters
std::string
Contact::get_first_name() const
{
	return first_name;
}

std::string
Contact::get_last_name() const
{
	return last_name;
}

std::string
Contact::get_nickname() const
{
	return nickname;
}

std::string
Contact::get_phone_number() const
{
	return phone_number;
}

std::string
Contact::get_darkest_secret() const
{
	return darkest_secret;
}

bool
Contact::is_valid() const
{
	return valid_contact;
}

// Creates a new contact given parameters
// Opted for this instead of individual setters since there's no need to edit individual values
// Switches flag for contact validity
Contact
Contact::create_contact()
{
	Contact contact;

	if (!contact.ask_first_name()
		|| !contact.ask_last_name()
		|| !contact.ask_nickname()
		|| !contact.ask_phone_number()
		|| !contact.ask_darkest_secret())
		return contact;

	contact.valid_contact = true;
	return contact;
}

bool Contact::name_is_valid(const std::string &name)
{
	for (int i = 0; name[i]; i++)
	{
		if (!isalpha(name[i]))
			return false;
	}
	return true;
}

// Checks if number only has 0-9
bool Contact::number_is_valid(const std::string &number)
{
	for (int i = 0; number[i]; i++)
	{
		if (!isdigit(number[i]))
			return false;
	}
	return true;
}

// Asks and validates first name
bool Contact::ask_first_name()
{
	std::cout << "First name: " << std::endl;
	std::getline(std::cin, first_name);
	if (first_name == "" || !name_is_valid(first_name))
	{
		std::cout << "Error: Invalid first name!" << std::endl;
		return false;
	}
	return true;
}

// Asks and validates last name
bool Contact::ask_last_name()
{
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, last_name);
	if (last_name == "" || !name_is_valid(last_name))
	{
		std::cout << "Error: Invalid last name!" << std::endl;
		return false;
	}
	return true;
}

// Asks and validates nickname
bool Contact::ask_nickname()
{
	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	if (nickname == "" || !name_is_valid(nickname))
	{
		std::cout << "Error: Invalid nickname!" << std::endl;
		return false;
	}
	return true;
}

// Asks and validates phone number
bool Contact::ask_phone_number()
{
	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phone_number);
	if (phone_number == "" || !number_is_valid(phone_number))
	{
		std::cout << "Error: Invalid phone number!" << std::endl;
		return false;
	}
	return true;
}

// Asks and validates darkest secret
bool Contact::ask_darkest_secret()
{
	std::cout << "Darkest Secret: " << std::endl;
	std::getline(std::cin, darkest_secret);
	if (darkest_secret == "")
	{
		std::cout << "Error: Invalid darkest secret!" << std::endl;
		return false;
	}
	return true;
}
