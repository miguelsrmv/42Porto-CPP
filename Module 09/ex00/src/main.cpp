#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sys/stat.h>

static bool
usage_check (int argc, char **argv)
{
	if (argc != 2)
		return false;

	std::ifstream input_file (argv[1]);
	if (!input_file.is_open ())
		return false;

	struct stat statbuf;
	if (stat (argv[1], &statbuf) != 0 || S_ISDIR (statbuf.st_mode))
		return false;

	return true;
}

int
main (int argc, char **argv)
{
	if (!usage_check (argc, argv))
		{
			std::cout << "Error: could not open file" << std::endl;
			return (1);
		}

	BitcoinExchange::calculate_values (argv[1]);
}
