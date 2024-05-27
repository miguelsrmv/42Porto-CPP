#include <string>

class Contact
{
  public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	Contact ()
	{
		first_name = "";
		last_name = "", nickname = "";
		phone_number = "";
		darkest_secret = "";
	}
};
