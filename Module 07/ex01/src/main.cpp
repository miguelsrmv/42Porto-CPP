#include "iter.hpp"
#include <iostream>

template <typename T>
static void
print_value (T value)
{
	std::cout << value << std::endl;
}

template <typename T>
static void
print_doubled_value (T value)
{
	std::cout << value * 2 << std::endl;
}

template <typename T>
static void
print_tripled_value (T value)
{
	std::cout << value * 3 << std::endl;
}

int
main (void)
{
	char c_array[7] = "Miguel";
	iter (c_array, 7, print_value<char>);
	std::cout << std::endl;

	int i_array[5] = { 1, 2, 3, 4, 5 };
	iter (i_array, 5, print_doubled_value<int>);
	std::cout << std::endl;

	float f_array[3] = { 1.0f, 2.0f, 3.0f };
	iter (f_array, 3, print_tripled_value<float>);
	std::cout << std::endl;
}
