#include "PmergeMe.hpp"
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

bool
input_is_valid (const std::string &input)
{
	int begin = 0;
	while (input[begin] == ' ')
		begin++;

	int end = input.size ();
	while (input[end] == ' ')
		end--;

	std::string trimmed_input = input.substr (begin, end - begin + 1);

	std::stringstream stream (trimmed_input);
	std::string token;
	long buffer;

	if (stream.peek () == std::stringstream::traits_type::eof ())
		return false;

	while (stream >> token)
		{
			std::stringstream small_stream (token);
			if (!(small_stream >> buffer) || buffer <= 0
				|| static_cast<long> (buffer)
					   > std::numeric_limits<int>::max ())
				return false;
		}

	return true;
}

template <typename container>
container
fill_in_container (container cont, char *input)
{
	std::stringstream stream (input);
	int buffer;

	while (stream >> buffer)
		cont.push_back (buffer);

	return cont;
}

template <typename container>
void
print_results (const char *input, const container &container_1, double time_1,
			   double time_2)
{
	// Prints original input
	std::cout << "Before: " << input << std::endl;

	// Prints sorted input
	std::cout << "After: ";
	for (typename container::const_iterator it = container_1.begin ();
		 it != container_1.end (); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	int container_size = container_1.size ();
	// Prints time it took for container #1 to be sorted
	std::cout << "Time to process a range of " << container_size
			  << " elements with std::vector " << time_1 << " us" << std::endl;

	// Prints time it took container #2 to be sorted
	std::cout << "Time to process a range of " << container_size
			  << " elements with std::list " << time_2 << " us" << std::endl;
}

int
main (int argc, char **argv)
{
	if (argc != 2 || !input_is_valid (argv[1]))
		{
			std::cout << "Error" << std::endl;
			return 1;
		}

	std::vector<int> vector = fill_in_container (std::vector<int> (), argv[1]);
	std::list<int> list = fill_in_container (std::list<int> (), argv[1]);

	if (Pmerge::there_are_duplicates (vector)
		|| Pmerge::there_are_duplicates (list))
		{
			std::cout << "Error: duplicates" << std::endl;
			return 2;
		}

	double time_1 = Pmerge::sort (vector);
	double time_2 = Pmerge::sort (list);

	print_results (argv[1], vector, time_1, time_2);

	return 0;
}
