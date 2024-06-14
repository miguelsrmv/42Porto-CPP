#include "SedIsForLosers.hpp"

void write_to_output_file(std::ifstream &input_stream,
						  std::ofstream &output_stream,
						  const std::string &string_1, const std::string &string_2)
{
	std::stringstream buffer;
	buffer << input_stream.rdbuf();

	std::string content;
	content = buffer.str();

	size_t position = 0;
	size_t found_pos;
	while (true)
	{
		found_pos = content.find(string_1, position);
		if (found_pos == std::string::npos)
			break ;
		output_stream << content.substr(position, found_pos - position);
		output_stream << string_2;
		position = found_pos + string_1.length();
	}
	output_stream << content.substr(position);
}

int main(int argc, char **argv)
{
	if (!correct_usage(argc, (const char **)argv))
		return (error_log(1));

	if (!valid_input_file((const char *)argv[1]))
		return (error_log(2));

	std::string target_file = std::string(argv[1]) + ".replace";
	if (!valid_output_file(target_file.c_str()))
		return (error_log(3));

	std::ifstream input_stream(argv[1], std::ios::in);
	if (!input_stream)
		return (error_log(4));

	std::ofstream output_stream(target_file.c_str(),
								std::ios::out | std::ios::trunc);
	if (!output_stream)
		return (error_log(5));

	const std::string string_1 = argv[2];
	const std::string string_2 = argv[3];

	write_to_output_file(input_stream, output_stream, string_1, string_2);
}
