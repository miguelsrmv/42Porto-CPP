#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <sys/time.h>

Pmerge::Pmerge () {}

Pmerge::Pmerge (const Pmerge &copy) { *this = copy; }

const Pmerge &
Pmerge::operator= (const Pmerge &copy)
{
	(void)copy;
	return *this;
}

Pmerge::~Pmerge () {}

double
Pmerge::get_time_diff (struct timeval start_time, struct timeval end_time)
{
	long seconds = end_time.tv_sec - start_time.tv_sec;

	long microseconds = end_time.tv_usec - start_time.tv_usec;

	double elapsed = seconds * 1000000 + microseconds;

	return (elapsed);
}

void
Pmerge::merge (std::vector<int> &container, std::vector<int> &left,
			   std::vector<int> &right)
{
	std::vector<int>::iterator temp_it = container.begin ();
	std::vector<int>::iterator left_it = left.begin ();
	std::vector<int>::iterator right_it = right.begin ();

	while (left_it != left.end () && right_it != right.end ())
		{
			if (*left_it < *right_it)
				*temp_it++ = *left_it++;
			else
				*temp_it++ = *right_it++;
		}
	while (left_it != left.end ())
		*temp_it++ = *left_it++;
	while (right_it != right.end ())
		*temp_it++ = *right_it++;
}

void
Pmerge::merge_container (std::vector<int> &container)
{
	if (container.size () == 1)
		return;

	std::vector<int> left (container.begin (),
						   container.begin () + container.size () / 2);
	std::vector<int> right (container.begin () + container.size () / 2,
							container.end ());

	merge_container (left);
	merge_container (right);

	merge (container, left, right);
}

void
Pmerge::merge (std::deque<int> &container, std::deque<int> &left,
			   std::deque<int> &right)
{
	std::deque<int>::iterator temp_it = container.begin ();
	std::deque<int>::iterator left_it = left.begin ();
	std::deque<int>::iterator right_it = right.begin ();

	while (left_it != left.end () && right_it != right.end ())
		{
			if (*left_it < *right_it)
				*temp_it++ = *left_it++;
			else
				*temp_it++ = *right_it++;
		}
	while (left_it != left.end ())
		*temp_it++ = *left_it++;
	while (right_it != right.end ())
		*temp_it++ = *right_it++;
}

void
Pmerge::merge_container (std::deque<int> &container)
{
	if (container.size () == 1)
		return;

	std::deque<int> left (container.begin (),
						  container.begin () + container.size () / 2);
	std::deque<int> right (container.begin () + container.size () / 2,
						   container.end ());

	merge_container (left);
	merge_container (right);

	merge (container, left, right);
}
