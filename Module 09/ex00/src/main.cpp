#include "BitcoinExchange.hpp"
#include <iostream>

int
main (int argc, char **argv)
{
	if (argc > 2)
		{
			std::cout << ERROR_USAGE << std::endl;
			return 1;
		}

	BitcoinExchange Exchange;

	if (!Exchange.input_is_valid (argv[1]))
		return 2;

	Exchange.print_values (argv[1]);
	return 0;
}
