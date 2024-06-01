#ifndef SEDLOSERS_HPP
#define SEDLOSERS_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>

// Check_usage.cpp
bool correct_usage (const int argc, const char **argv);
bool valid_input_file (const char *input_file_path);
bool valid_output_file (const char *output_file_path);

// Write_to_file.cpp
void	load_contents_to_buffer(const char *input_file, std::stringstream& buffer);
void 	write_to_output_file (const char *input_file, std::string &target_file,
						    std::string& string_1, std::string& string_2);

#endif