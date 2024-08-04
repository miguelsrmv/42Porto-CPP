#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <sys/stat.h>

#define ERROR_USAGE "Error: Usage is './btc [input_file]'."
#define ERROR_INVALID_FILE "Error: could not open file."
#define ERROR_DIR_FILE "Error: file is a directory."
#define ERROR_EMPTY_FILE "Error: empty file."
#define ERROR_INVALID_HEADER "Error: invalid input header."
#define ERROR_BAD_INPUT "Error: bad input => "
#define ERROR_NEGATIVE_NUMBER "Error: not a positive number."
#define ERROR_LARGE_NUMBER "Error: too large a number."

typedef std::map<std::string, float> map;

class BitcoinExchange
{
  public:
	BitcoinExchange ();
	BitcoinExchange (const BitcoinExchange &copy);
	const BitcoinExchange &operator= (const BitcoinExchange &copy);
	~BitcoinExchange ();

	bool input_is_valid (const char *input_file);
	bool print_values (const char *input_file);

  private:
	map _database;

	// Functions related to processing of _database
	map::iterator get_closest_date (const std::string &date);
	float calculate_total (const std::string &date, const std::string &value);

	// Functions related to date parsing
	bool date_is_valid (const std::string &date, const std::string &buffer);
	bool date_format_is_valid (const std::string &date);
	bool date_value_is_valid (const std::string &date);
	std::tm get_time_struct (const std::string &date);

	// Functions related to value parsing
	bool value_is_valid (const std::string &value, const std::string &buffer);

	// General purpose functions
	std::string trim_whitespaces (const std::string &string);
	bool error_log (const std::string &message);
};

#endif
