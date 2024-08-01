#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <sys/stat.h>

#define ERROR_USAGE "Error: Usage is './btc [input_file]'"
#define ERROR_INVALID_FILE "Error: could not open file"
#define ERROR_EMPTY_FILE "Error: empty file!"
#define ERROR_BAD_INPUT "Error: bad input => "
#define ERROR_NEGATIVE_NUMBER "Error: not a positive number"

class BitcoinExchange
{
  public:
	BitcoinExchange ();
	BitcoinExchange (const BitcoinExchange &copy);
	const BitcoinExchange &operator= (const BitcoinExchange &copy);
	~BitcoinExchange ();

	bool input_is_valid (const char *input_file);
	int calculate_values (const char *input_file);

  private:
	std::map<std::string, float> _database;
	float calculate_total (const std::string &date, const std::string &value);

	// Functions related to date parsing
	bool date_is_valid (const std::string &date);
	bool date_format_is_valid (const std::string &date);
	bool date_value_is_valid (const std::string &date);
	std::tm get_time_struct (const std::string &date);

	// Functions related to value parsing
	bool value_is_valid (const std::string &value);

	// General purpose functions
	std::string trim_whitespaces (const std::string &string);
	bool error_log (const std::string &message);
};

#endif
