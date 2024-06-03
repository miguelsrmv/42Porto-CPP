#include "Harl.hpp"

int
main (int argc, char **argv)
{
	if (argc != 2)
		{
			std::cerr << "Error: "
					  << "Usage: './Harl [level_code]" << std::endl;
			return (1);
		}

	std::string level (argv[1]);
	Harl Harl_object;
	Harl_object.complain (level);
}
