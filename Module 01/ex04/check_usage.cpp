#include "SedIsForLosers.hpp"

// Checks if there's a proper number of arguments and if file doesn't have an
// empty name
bool
correct_usage (const int argc, const char **argv)
{
	if (argc != 4 || !strlen (argv[1]))
		return (false);
	return (true);
}

// Checks if file is openable and readable (but tolerates empty files)
bool
valid_input_file (const char *input_file_path)
{
	char byte;
	std::ifstream input_file (input_file_path);

	if (!input_file.is_open ()
		|| (!input_file.read (&byte, 1) && !input_file.eof ()))
		return (false);
	return (true);
}

// Checks if file is openable and writeable
bool
valid_output_file (const char *output_file_path)
{
	char byte;
	std::ofstream output_file (output_file_path);

	if (!output_file.is_open () || !output_file.write (&byte, 1))
		return (false);
	return (true);
}
