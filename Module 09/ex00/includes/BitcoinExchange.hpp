#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange
{
  public:
	BitcoinExchange ();
	BitcoinExchange (const BitcoinExchange &copy);
	const BitcoinExchange &operator= (const BitcoinExchange &copy);
	~BitcoinExchange ();

	static void calculate_values (const char *input_file);

  private:
	std::map<std::string, float> _database;

	static bool get_values_to_database ();
};

#endif
