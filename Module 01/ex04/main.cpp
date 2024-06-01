#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

// Checks if there's a proper number of arguments and if file doesn't have an empty name
bool
correct_usage (const int argc, const char **argv)
{
	if (argc != 4 || !strlen (argv[1]))
		{
			std::cerr << "Incorrect usage! Please use: "
						 "'./SedIsForLosers Filename String1 String2'"
					  << std::endl;
			return (false);
		}
	return (true);
}

// Checks if file is openable and readable
bool
valid_input_file (char *input_file_path)
{
	char byte;
	std::ifstream input_file (input_file_path);

	if (!input_file.is_open () || !input_file.read(&byte, 1))
		{
			std::cerr << "Invalid input file!" << std::endl;
			return (false);
		}
	return (true);
}

bool
valid_output_file (const std::ifstream &input_file, std::ofstream &output_file)
{
	(void)input_file;
	(void)output_file;
	return (true);
}

int
main (int argc, char **argv)
{
	if (!correct_usage (argc, (const char **)argv))
		return (1);

	if (!valid_input_file (argv[1]))
		return (2);

}