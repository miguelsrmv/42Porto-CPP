#include "SedIsForLosers.hpp"

// Checks if there's a proper number of arguments and if file / string_1 don't have an
// empty name
bool
correct_usage (const int argc, const char **argv)
{
	if (argc != 4 || !strlen (argv[1]) || !strlen(argv[2]))
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

// Prints error message depending on error code
int
error_log (const int error_code)
{
	std::string error_message;

	if (error_code == 1)
		error_message = "Incorrect usage! Please use: "
						"'./SedIsForLosers [Filename (non-null)] [String1 (non-null)] [String2]'";
	else if (error_code == 2)
		error_message = "Invalid input file!";
	else if (error_code == 3)
		error_message = "Invalid output file!";
	else if (error_code == 4)
		error_message = "Unable to open input stream";
	else if (error_code == 5)
		error_message = "Unable to open output stream";

	std::cerr << "Error: " << error_message << std::endl;
	return (error_code);
}
