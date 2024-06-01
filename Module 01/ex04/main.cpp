#include "SedIsForLosers.hpp"

int
main (int argc, char **argv)
{
	if (!correct_usage (argc, (const char **)argv))
		return (1);

	if (!valid_input_file ((const char *)argv[1]))
		return (2);

	std::string target_file = std::string (argv[1]) + ".replace";
	if (!valid_output_file (target_file.c_str ()))
		return (3);

	write_to_output_file ((const char *)argv[1], target_file,
						  (const char *)argv[2], (const char *)argv[3]);
}