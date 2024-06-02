#include "SedIsForLosers.hpp"

void
write_to_output_file (const char *input_file, const char *output_file,
					  std::string &string_1, std::string &string_2)
{
	std::ifstream input_stream (input_file);
	std::ofstream output_stream (output_file);
	std::stringstream buffer;

	buffer << input_stream.rdbuf ();

	for (std::string::size_type i = 0; i < buffer.str ().length (); i++)
		{
			if (string_1.length ()
				&& buffer.str ().compare (i, string_1.length (), string_1)
					   == 0)
				{
					output_stream << string_2;
					i += string_1.length () - 1;
				}
			else
				output_stream << buffer.str ()[i];
		}
}

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

	std::string string_1 = argv[2];
	std::string string_2 = argv[3];

	write_to_output_file ((const char *)argv[1],
						  (const char *)target_file.c_str (), string_1,
						  string_2);
}