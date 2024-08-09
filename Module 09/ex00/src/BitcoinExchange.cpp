#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

/// Orthodox Canonical Form
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

/// Public functions
// Checks if data.csv is a valid file
bool
BitcoinExchange::load_data ()
{
	if (!input_is_valid ("data.csv"))
		return false;

	std::ifstream data_csv ("data.csv");
	std::string buffer;
	std::getline (data_csv, buffer);

	// Checks if the header is correct
	if (buffer != "date,exchange_rate")
		return error_log (ERROR_DATA_CSV);

	while (std::getline (data_csv, buffer))
		{
			size_t divider = buffer.find (",");
			std::string date = trim_whitespaces (buffer.substr (0, divider));
			std::string floatstring
				= trim_whitespaces (buffer.substr (divider + 1));
			if (date_format_is_valid (date) && value_is_valid (floatstring))
				{
					float value;
					std::stringstream ss (floatstring);
					ss >> value;
					_database[date] = value;
				}
			else
				return error_log (ERROR_DATA_CSV);
		}

	// Makes sure there was at least one data got put onto _database
	if (_database.size () == 0)
		return error_log (ERROR_DATA_CSV);

	return true;
}

// Checks if input file is valid
bool
BitcoinExchange::input_is_valid (const char *input_file)
{
	// Check if input was given
	if (!input_file)
		return error_log (ERROR_INVALID_FILE);

	// Check if file has read permissions
	std::ifstream input (input_file);
	if (!input.is_open ())
		return error_log (ERROR_INVALID_FILE);

	// Check if file is a dir
	struct stat statbuf;
	if (stat (input_file, &statbuf) != 0 || S_ISDIR (statbuf.st_mode))
		return error_log (ERROR_DIR_FILE);

	return true;
}

// Iterates through map to print each value
bool
BitcoinExchange::print_values (const char *input_file)
{
	std::ifstream input (input_file);
	std::string buffer;

	// Checks if file is empty
	if (!std::getline (input, buffer))
		return error_log (ERROR_EMPTY_FILE);

	// Checks if header is correct
	if (buffer != "date | value")
		return error_log (ERROR_INVALID_HEADER);

	while (std::getline (input, buffer))
		{
			if (std::count (buffer.begin (), buffer.end (), '|') != 1)
				{
					error_log (std::string (ERROR_BAD_INPUT) + buffer);
					continue;
				}
			size_t divider = buffer.find ('|');
			std::string date = trim_whitespaces (buffer.substr (0, divider));
			std::string value = trim_whitespaces (buffer.substr (divider + 1));
			if (date_is_valid (date, buffer) && value_is_valid (value, buffer))
				std::cout << date << " => " << value << " => "
						  << calculate_total (date, value) << std::endl;
		}

	return true;
}

/// Functions related to processing of _database
// Gets closest date
map::iterator
BitcoinExchange::get_closest_date (const std::string &date)
{
	std::tm target_time = get_time_struct (date);
	map::iterator date_it = _database.begin ();

	// Iterate until date goes just above the target_time
	while (date_it != _database.end ())
		{
			std::tm it_time = get_time_struct (date_it->first);
			if (std::mktime (&it_time) > std::mktime (&target_time))
				return (--date_it);
			date_it++;
		}

	// If nothing was found, return latest value in database
	return --date_it;
}

// Returns total value
float
BitcoinExchange::calculate_total (const std::string &date,
								  const std::string &value)
{
	std::istringstream ss (value);
	float fvalue;
	ss >> fvalue;

	map::iterator it = _database.find (date);
	if (it == _database.end ())
		it = get_closest_date (date);

	return (it->second * fvalue);
}

/// Functions related to date parsing
// Checks for valid date format and valid date value
bool
BitcoinExchange::date_is_valid (const std::string &date,
								const std::string &buffer)
{
	if (!date_format_is_valid (date) || !date_value_is_valid (date))
		return error_log (std::string (ERROR_BAD_INPUT) + buffer);

	return true;
}

// Checks if date format is valid
bool
BitcoinExchange::date_format_is_valid (const std::string &date)
{
	// Checks that date format is of length 10
	if (date.size () != 10)
		return false;

	// Checks that date format is of format XXXX-XX-XX
	if (date[4] != '-' || date[7] != '-')
		return false;

	// Checks that each 'X' is a digit
	for (int i = 0; i < 10; i++)
		{
			if (i == 4 || i == 7)
				continue;
			if (!isdigit (date[i]))
				return false;
		}

	return true;
}

// Checks if date is valid
bool
BitcoinExchange::date_value_is_valid (const std::string &date)
{
	std::tm tm = get_time_struct (date);

	// Returns false if it's not a date
	tm.tm_mon -= 1;
	tm.tm_year -= 1900;

	std::tm normalized = tm;
	if (std::mktime (&normalized) == -1)
		return false;

	if ((normalized.tm_year != tm.tm_year || normalized.tm_mon != tm.tm_mon
		 || normalized.tm_mday != tm.tm_mday))
		return false;

	// Returns false if the date is earlier than the first database value
	std::tm first_tm = get_time_struct (_database.begin ()->first);
	first_tm.tm_mon -= 1;
	first_tm.tm_year -= 1900;

	if (std::mktime (&tm) < std::mktime (&first_tm))
		return false;

	return true;
}

// Returns std::tm struct from given date
std::tm
BitcoinExchange::get_time_struct (const std::string &date)
{
	std::tm tm;
	std::stringstream ss;

	ss.str (date.substr (0, 4));
	ss >> tm.tm_year;
	ss.clear ();

	ss.str (date.substr (5, 2));
	ss >> tm.tm_mon;
	ss.clear ();

	ss.str (date.substr (8, 2));
	ss >> tm.tm_mday;
	ss.clear ();

	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	tm.tm_isdst = -1;

	return tm;
}

// Checks for valid amount values (int or float from 0 to 1000)
bool
BitcoinExchange::value_is_valid (const std::string &value,
								 const std::string &buffer)
{
	// Excludes empty numbers
	if (value.empty ())
		return error_log (std::string (ERROR_BAD_INPUT) + buffer);

	size_t i = 0;

	// Excludes negative numbers
	if (value[i] == '-')
		return error_log (ERROR_NEGATIVE_NUMBER);

	// Tolerates one +
	if (value[i] == '+')
		i++;

	// Checks if all characters are digits or dots
	while (i < value.size ())
		{
			char c = value[i];
			if (!isdigit (c) && (c != '.'))
				return error_log (std::string (ERROR_BAD_INPUT) + buffer);
			i++;
		}

	// Makes sure there is only one dot.
	int dot_count = std::count (value.begin (), value.end (), '.');

	if (dot_count > 1)
		return error_log (std::string (ERROR_BAD_INPUT) + buffer);

	// If there is a dot, there must be at least 1 character before it and 1
	// character after
	if (dot_count)
		{
			if (value.find ('.') == 0
				|| value.find ('.') == value.length () - 1)
				return error_log (std::string (ERROR_BAD_INPUT) + buffer);
		}

	// Checks that the number is, at most, 1000
	std::string unit_part = value.substr (0, value.find ('.'));
	if (unit_part != "1000" && unit_part.length () > 3)
		return error_log (ERROR_LARGE_NUMBER);

	return true;
}

// Checks for valid amount values (int or float from 0 to 1000)
bool
BitcoinExchange::value_is_valid (const std::string &value)
{
	// Excludes empty numbers
	if (value.empty ())
		return false;

	size_t i = 0;

	// Tolerates one +
	if (value[i] == '+')
		i++;

	// Checks if all characters are digits or dots
	while (i < value.size ())
		{
			char c = value[i];
			if (!isdigit (c) && (c != '.'))
				return false;
			i++;
		}

	// Makes sure there is only one dot
	int dot_count = std::count (value.begin (), value.end (), '.');

	if (dot_count > 1)
		return false;

	// If there is a dot, there must be at least 1 character before it and 1
	// character after
	if (dot_count)
		{
			if (value.find ('.') == 0
				|| value.find ('.') == value.length () - 1)
				return false;
		}

	return true;
}

// Trims whitespace from string
std::string
BitcoinExchange::trim_whitespaces (const std::string &string)
{
	int iterator_begin = 0;
	int iterator_end = string.length () - 1;

	while (string[iterator_begin] == ' ')
		iterator_begin++;

	while (string[iterator_end] == ' ')
		iterator_end--;

	std::string trimmed_string
		= string.substr (iterator_begin, iterator_end + 1);

	return trimmed_string;
}

// Logs errors
bool
BitcoinExchange::error_log (const std::string &message)
{
	std::cout << message << std::endl;

	return false;
}
