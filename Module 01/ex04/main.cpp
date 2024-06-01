#include "SedIsForLosers.hpp"

void
write_to_output_file (std::string &target_file, char *string_1, char *string_2)
{
	(void)target_file;
	(void)string_1;
	(void)string_2;
}

int
main (int argc, char **argv)
{
	if (!correct_usage (argc, (const char **)argv))
		return (1);

	if (!valid_input_file (argv[1]))
		return (2);

	std::string target_file = std::string (argv[1]) + std::string (".replace");
	if (!valid_output_file (target_file.c_str ()))
		return (3);

	write_to_output_file (target_file, argv[2], argv[3]);
}