#include "BitcoinExchange.hpp"
#include <ctime>
#include <sstream>

// Orthodox Canonical Form
BitcoinExchange::BitcoinExchange ()
{
	std::ifstream data_csv ("data.csv");

	std::string buffer;
	std::getline (data_csv, buffer);
	while (std::getline (data_csv, buffer))
		{
			size_t divider = buffer.find (",");
			std::string date = buffer.substr (0, divider);
			float value = atof (buffer.substr (divider + 1).c_str ());
			_database[date] = value;
		}
}

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

bool
BitcoinExchange::date_format_is_valid (const std::string &date)
{
	if (date.size () != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
		{
			if (i == 4 || i == 7)
				continue;
			if (!isdigit (date[i]))
				return false;
		}

	return true;
}

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

bool
BitcoinExchange::date_value_is_valid (const std::string &date)
{
	std::tm tm = get_time_struct (date);

	// Returns false if it's not a date
	if (std::mktime (&tm) == -1)
		return false;

	// Returns false if the date is earlier than the first database value
	std::tm first_tm = get_time_struct (_database.begin ()->first);
	if (std::mktime (&tm) < std::mktime (&first_tm))
		return false;

	return true;
}

bool
BitcoinExchange::date_is_valid (const std::string &date)
{
	if (!date_format_is_valid (date) || !date_value_is_valid (date))
		return error_log (std::string (ERROR_BAD_INPUT) + date);

	return true;
}

bool
BitcoinExchange::value_is_valid (const std::string &value)
{
	// Excludes empty numbers
	if (value.empty ())
		return error_log (std::string (ERROR_BAD_INPUT) + value);

	// Excludes negative numbers
	if (value[0] == '-')
		return error_log (ERROR_NEGATIVE_NUMBER);

	size_t i = 0;

	// Tolerates one +
	if (value[i] == '+')
		i++;

	// Checks if all characters are digits, dots or 'f'
	while (i < value.size ())
		{
			char c = value[i];
			if (!isdigit (c) && (c != '.') && c != 'f')
				return error_log (std::string (ERROR_BAD_INPUT) + value);
			i++;
		}

	// Makes sure there is only one dot and one f.
	// The existance of is also dependant on the existance of the dot.
	int dot_count = std::count (value.begin (), value.end (), '.');
	int f_count = std::count (value.begin (), value.end (), 'f');

	if (dot_count > 1 || f_count > 1 || (f_count == 1 && dot_count == 0))
		return error_log (std::string (ERROR_BAD_INPUT) + value);

	// If there is a dot, there must be a character before it
	if (dot_count)
		{
			if (value.find ('.') == 0)
				return error_log (std::string (ERROR_BAD_INPUT) + value);
		}

	// If there is an f and a dot, there must be a character in between
	if (dot_count && f_count)
		{
			int dot_position = value.find ('.');
			int f_position = value.find ('f');
			if (f_position - dot_position < 2)
				return error_log (std::string (ERROR_BAD_INPUT) + value);
		}

	// Checks that the number is, at most, 1000
	std::string unit_part = value.substr (0, value.find ('.'));
	if (unit_part != "1000" && unit_part.length () > 3)
		return error_log (ERROR_LARGE_NUMBER);

	return true;
}

// TODO Review this function!
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
	return _database.end ();
}

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

bool
BitcoinExchange::calculate_values (const char *input_file)
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
			if (date_is_valid (date) && value_is_valid (value))
				std::cout << date << " => " << value << " => "
						  << calculate_total (date, value) << std::endl;
		}

	return true;
}

bool
BitcoinExchange::error_log (const std::string &message)
{
	std::cout << message << std::endl;
	return false;
}
