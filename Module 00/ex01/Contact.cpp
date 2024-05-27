#include <iostream>
#include <string>

class Contact
{
  public:
	Contact ()
	{
		first_name = "";
		last_name = "";
		nickname = "";
		phone_number = "";
		darkest_secret = "";
	}

	~Contact () {}

	// Getters
	std::string
	get_first_name ()
	{
		return first_name;
	}

	std::string
	get_last_name ()
	{
		return last_name;
	}

	std::string
	get_nickname ()
	{
		return nickname;
	}

	std::string
	get_phone_number ()
	{
		return phone_number;
	}
	
	std::string
	get_darkest_secret ()
	{
		return darkest_secret;
	}

	// Creates a new contact given parameters
	// Opted for this instead of individual setters since there's no need to edit individual values
	// Includes checks for contact validity
	static Contact
	create_contact ()
	{
		Contact contact;
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
				return contact;
			}

		std::cout << "Last name: " << std::endl;
		std::getline (std::cin, last_name);
		if (last_name == "" || !name_is_valid (last_name))
			{
				std::cout << "Error: Invalid last name!" << std::endl;
				return contact;
			}

		std::cout << "Nickname: " << std::endl;
		std::getline (std::cin, nickname);
		if (nickname == "" || !name_is_valid (nickname))
			{
				std::cout << "Error: Invalid nickname!" << std::endl;
				return contact;
			}

		std::cout << "Phone number: " << std::endl;
		std::getline (std::cin, phone_number);
		if (phone_number == "" || !number_is_valid (phone_number))
			{
				std::cout << "Error: Invalid phone number!" << std::endl;
				return contact;
			}

		std::cout << "Darkest Secret: " << std::endl;
		std::getline (std::cin, darkest_secret);
		if (darkest_secret == "")
			{
				std::cout << "Error: Invalid darkest secret!" << std::endl;
				return contact;
			}

		contact.first_name = first_name;
		contact.last_name = last_name;
		contact.nickname = nickname;
		contact.phone_number = phone_number;
		contact.darkest_secret = darkest_secret;

		return contact;
	}

  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	// Checks if name only has a-z and A-Z
	static bool
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
	static bool
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
