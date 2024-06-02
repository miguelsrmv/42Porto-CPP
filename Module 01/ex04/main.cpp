#include "SedIsForLosers.hpp"

void
write_to_output_file (std::ifstream &input_stream,
					  std::ofstream &output_stream,
					  const std::string &string_1, const std::string &string_2)
{
	std::stringstream buffer;
	buffer << input_stream.rdbuf ();

	std::string content;
	content = buffer.str ();

	for (std::string::size_type i = 0; i < content.length (); i++)
		{
			if (!string_1.empty ()
				&& content.compare (i, string_1.length (), string_1) == 0)
				{
					output_stream << string_2;
					i += string_1.length () - 1;
				}
			else
				output_stream << content[i];
		}
}

int
main (int argc, char **argv)
{
	if (!correct_usage (argc, (const char **)argv))
		{
			std::cerr << "Error: Incorrect usage! Please use: "
						 "'./SedIsForLosers Filename String1 String2'"
					  << std::endl;
			return (1);
		}

	if (!valid_input_file ((const char *)argv[1]))
		{
			std::cerr << "Error: Invalid input file!" << std::endl;
			return (2);
		}

	std::string target_file = std::string (argv[1]) + ".replace";
	if (!valid_output_file (target_file.c_str ()))
		{
			std::cerr << "Error: Invalid output file!" << std::endl;
			return (3);
		}

	std::ifstream input_stream (argv[1], std::ios::in);
	if (!input_stream)
		{
			std::cerr << "Error: Unable to open input stream" << std::endl;
			return (4);
		}

	std::ofstream output_stream (target_file.c_str ());
	if (!output_stream, std::ios::out | std::ios::trunc)
		{
			std::cerr << "Error: Unable to open output stream" << std::endl;
			return (5);
		}

	const std::string string_1 = argv[2];
	const std::string string_2 = argv[3];

	write_to_output_file (input_stream, output_stream, string_1, string_2);
}