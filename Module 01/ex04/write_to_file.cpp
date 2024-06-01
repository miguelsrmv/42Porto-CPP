#include "SedIsForLosers.hpp"

void	load_contents_to_buffer(const char *input_file, std::stringstream& buffer)
{
	std::ifstream target_file_istream (input_file);

	buffer << target_file_istream.rdbuf ();
}

void
write_to_output_file (const char *input_file, std::string& target_file,
					  std::string& string_1, std::string& string_2)
{
	std::stringstream 	buffer;

	load_contents_to_buffer(input_file, buffer);

	for (std::string::size_type i = 0; i < buffer.str().length(); i++)
	{
		if (buffer.str().compare(i, string_1.length(), string_1) == 0)
		{
			std::cout << string_2;
			i += string_1.length() - 1;
		}
		else
			std::cout << buffer.str()[i];
	}
	(void)target_file;
}