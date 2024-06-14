#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();

private:
	Contact contact_list[8];
	int last_contact_index;

	void print_contact(const Contact &contact, const std::string &index);
	std::string truncate_string(const std::string &string);
	bool index_is_invalid(const std::string &index);
};

#endif