#include "PmergeMe.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

bool
input_is_valid (const std::string &input)
{
	std::stringstream stream (input);
	std::string token;
	long buffer;

	while (stream >> token)
		{
			std::stringstream small_stream (token);
			if (!(small_stream >> buffer) || buffer <= 0
				|| buffer > std::numeric_limits<int>::max ())
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
			  << " elements with container #1 " << time_1 << std::endl;

	// Prints time it took container #2 to be sorted
	std::cout << "Time to process a range of " << container_size
			  << " elements with container #2 " << time_2 << std::endl;
}

void
print_results2 (const char *input, std::vector<int> &container_1,
				std::list<int> &container_2, double time_1, double time_2)
{
	// Prints original input
	std::cout << "Before: " << input << std::endl;

	// Prints sorted input
	std::cout << "[VECTOR] After: ";
	for (std::vector<int>::const_iterator it = container_1.begin ();
		 it != container_1.end (); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "[LIST] After: ";
	for (std::list<int>::const_iterator it = container_2.begin ();
		 it != container_2.end (); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	int container_size = container_1.size ();

	// Prints time it took for container #1 to be sorted
	std::cout << "Time to process a range of " << container_size
			  << " elements with container #1 " << time_1 << std::endl;

	// Prints time it took container #2 to be sorted
	std::cout << "Time to process a range of " << container_size
			  << " elements with container #2 " << time_2 << std::endl;
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
	std::deque<int> deque = fill_in_container (std::deque<int> (), argv[1]);
	std::list<int> list = fill_in_container (std::list<int> (), argv[1]);

	double time_1 = Pmerge::sort (vector);
	double time_2 = Pmerge::sort (list);

	print_results2 (argv[1], vector, list, time_1, time_2);

	return 0;
}
