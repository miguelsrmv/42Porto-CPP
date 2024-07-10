#include "Data.hpp"

Data::Data() : _name("Miguel"), _age(35), _height(1.9f), _net_worth(9001) {}

Data::Data(const Data& copy)
{
	*this = copy;
}

const Data&
Data::operator=(const Data& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_age = copy._age;
		_height = copy._height;
		_net_worth = copy._net_worth;
	}
	return (*this);
}

Data::~Data() {}

std::ostream& operator<<(std::ostream& outstream, const Data& copy)
{
	std::cout << "Data structure:" << std::endl;
	std::cout << "Name: " << copy._name << std::endl;
	std::cout << "Age: " << copy._age << std::endl;
	std::cout << "Height: " << copy._height << std::endl;
	std::cout << "Net worth: " << copy._net_worth << std::endl;

	return (outstream);
}
