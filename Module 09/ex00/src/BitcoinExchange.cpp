#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &copy)
{
	*this = copy;
}

const BitcoinExchange &
BitcoinExchange::operator= (const BitcoinExchange &copy)
{
	if (this != &copy)
		this->_database = copy._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange () {}

bool
BitcoinExchange::get_values_to_database ()
{
	std::ifstream input ("data.csv");

	std::string buffer;
	std::getline (input, buffer);
	while (std::getline (input, buffer))
		{
			;
		}

	return (true);
}

void
BitcoinExchange::calculate_values (const char *input_file)
{
	if (!get_values_to_database ())
		return;
	(void)input_file;
}
