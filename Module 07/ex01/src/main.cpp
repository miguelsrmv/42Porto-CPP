#include "iter.hpp"
#include <iostream>

template <class T>
void
iter (T *array_address, std::size_t length, void (*f) (T))
{
	for (size_t index = 0; index < length; index++)
		f (array_address[index]);

	std::cout << std::endl;
}

template <class T>
void
test_function (T value)
{
	std::cout << value << std::endl;
}

int
main (void)
{
	int int_array[5] = { 1, 2, 3 };
	float float_array[5] = { 6.1f, 7.2f, 8.3f, 9.4f };
	char char_array[7] = "Miguel";

	iter (int_array, 3, test_function);

	iter (float_array, 4, test_function);

	iter (char_array, 7, test_function);
}
