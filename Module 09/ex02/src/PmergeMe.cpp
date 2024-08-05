#include "PmergeMe.hpp"
#include <cstddef>

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

double
Pmerge::merge (std::vector<int> container)
{
	timeval start_time;
	gettimeofday (&start_time, NULL);

	merge_container (container);

	timeval end_time;
	gettimeofday (&end_time, NULL);

	return (get_time_diff (start_time, end_time));
}

double
Pmerge::merge (std::deque<int> container)
{
	timeval start_time;
	gettimeofday (&start_time, NULL);

	merge_container (container);

	timeval end_time;
	gettimeofday (&end_time, NULL);

	return (get_time_diff (start_time, end_time));
}

void
Pmerge::merge_container (std::vector<int> container)
{
	(void)container;
	return;
}

void
Pmerge::merge_container (std::deque<int> container)
{
	(void)container;
	return;
}
