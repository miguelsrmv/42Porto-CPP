#include <string>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

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
	static Contact
	set_contact (std::string first_name, std::string last_name,
				 std::string nickname, std::string phone_number,
				 std::string darkest_secret)
	{
		Contact contact;

		contact.first_name = first_name;
		contact.last_name = last_name;
		contact.nickname = nickname;
		contact.phone_number = phone_number;
		contact.darkest_secret = darkest_secret;

		return (contact);
	}
};
