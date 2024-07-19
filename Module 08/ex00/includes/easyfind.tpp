// vim: set filetype=cpp :

#include <algorithm>
#include <iostream>

template <typename T>
int
easyfind (T container, int target)
{
	typename T::iterator iter;

	iter = std::find (container.begin (), container.end (), target);
	if (iter == container.end ())
		std::cout << "Couldn't find " << target << std::endl;

	return std::distance (container.begin (), iter);
}
