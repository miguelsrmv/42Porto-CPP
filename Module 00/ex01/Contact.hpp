#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <limits>

class Contact
{
  public:
	Contact ();
	~Contact ();

	std::string get_first_name () const;
	std::string get_last_name () const;
	std::string get_nickname () const;
	std::string get_phone_number () const;
	std::string get_darkest_secret () const;
	bool is_valid () const;

	static Contact create_contact ();

  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	bool valid_contact;

	static bool name_is_valid (const std::string& name);
	static bool number_is_valid (const std::string& number);
	bool ask_first_name ();
	bool ask_last_name ();
	bool ask_nickname ();
	bool ask_phone_number ();
	bool ask_darkest_secret ();
};

#endif