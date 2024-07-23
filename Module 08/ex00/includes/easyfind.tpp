// vim: set filetype=cpp :
#include "easyfind.hpp"

#include <algorithm>
#include <iostream>

template <typename T>
void
easyfind (T container, int value_to_find)
{
	typename T::iterator it;

	it = std::find (container.begin (), container.end (), value_to_find);

	if (it == container.end ())
		std::cout << "Couldn't find value [" << value_to_find << "]"
				  << std::endl;
	else
		std::cout << "Found value [" << value_to_find << "] on position "
				  << std::distance (container.begin (), it) << std::endl;
}
