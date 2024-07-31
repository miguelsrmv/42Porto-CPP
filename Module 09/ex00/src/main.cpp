#include "BitcoinExchange.hpp"

int
main (int argc, char **argv)
{
	BitcoinExchange Exchange;

	if (argc > 2)
		{
			std::cout << ERROR_USAGE << std::endl;
			return 1;
		}
	else if (!Exchange.input_is_valid (argv[1]))
		{
			std::cout << ERROR_EMPTY_FILE << std::endl;
			return 2;
		}
	else
		return (Exchange.calculate_values (argv[1]));
}
