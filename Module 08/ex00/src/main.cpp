#include "easyfind.hpp"

#include <deque>
#include <list>
#include <vector>

template <typename T>
void
test_container (T &container, const char *container_type)
{
	std::cout << "Testing a " << container_type << " container" << std::endl;

	(void)container;

	for (int i = -2; i < 2; i++)
		container.push_back (i);

	container.push_back (0);

	
	easyfind (container, -1);
	easyfind (container, 0);
	easyfind (container, 1);
	easyfind (container, 999);
	easyfind (container, -999);

	std::cout << std::endl;
}

int
main (void)
{
	std::vector<int> vector_to_test;
	std::list<int> list_to_test;
	std::deque<int> deque_to_list;

	test_container (vector_to_test, "vector");
	test_container (list_to_test, "list");
	test_container (deque_to_list, "deque");
}
