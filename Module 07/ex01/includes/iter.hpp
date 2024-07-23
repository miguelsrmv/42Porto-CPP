#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename function_type>
void
iter (T *array, size_t array_length, function_type function)
{
	for (size_t i = 0; i < array_length; i++)
		function (array[i]);
}

#endif
