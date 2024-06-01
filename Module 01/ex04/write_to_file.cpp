#include "SedIsForLosers.hpp"

void	load_contents_to_buffer(const char *input_file, std::stringstream& buffer)
{
	std::ifstream target_file_istream (input_file);

	buffer << target_file_istream.rdbuf ();
}

void
write_to_output_file (const char *input_file, std::string& target_file,
					  const char *string_1, const char *string_2)
{
	std::stringstream buffer;

	load_contents_to_buffer(input_file, buffer);

	std::cout << "BEFORE SUBSTITUTION: " << std::endl ;
	std::cout << buffer.str () << std::endl;

	// Substitute buffer

	update_string(buffer, string_1 , string_2);

	std::cout << std::endl << std::endl << "AFTER SUBSTITUTION: " << std::endl ;
	std::cout << buffer.str () << std::endl;

	unload_contents_from_buffer(target_file, buffer);
}
void	update_string(std::stringstream& buffer, const char *string_1, const char *string_2)
{
	(void)buffer;
	(void)string_1;
	(void)string_2;
}

void	unload_contents_from_buffer(std::string& target_file, std::stringstream& buffer)
{
	(void)target_file;
	std::cout << buffer.str () << std::endl;
}