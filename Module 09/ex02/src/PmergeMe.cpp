#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
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

int
Pmerge::get_max (int a, int b)
{
	return (a > b ? a : b);
}

int
Pmerge::get_min (int a, int b)
{
	return (a < b ? a : b);
}

void
Pmerge::Ford_Johnson (std::vector<int> &container)
{
	std::vector<pair> pairs;
	create_pairs (container, pairs);
	merge_sort_pairs (pairs);

	int struggler;
	create_struggler (container, struggler);

	std::vector<int> temp_container;
	create_main_chain (pairs, temp_container);

	insertion_sort_pairs (pairs, temp_container);

	if (struggler)
		{
			std::vector<int>::iterator final_insertion = binary_search (
				struggler, temp_container.size (), temp_container);
			temp_container.insert (final_insertion, struggler);
		}

	container = temp_container;
}

void
Pmerge::create_pairs (std::vector<int> &container, std::vector<pair> &pairs)
{
	int pairs_size = container.size () / 2;

	pairs.resize (pairs_size);
	pairs.assign (pairs_size, std::vector<int> (2));

	std::vector<int>::iterator big_it = container.begin ();

	for (std::vector<pair>::iterator small_it = pairs.begin ();
		 small_it != pairs.end (); small_it++)
		{
			(*small_it)[MAIN] = get_max (*big_it, *(big_it + 1));
			(*small_it)[PEND] = get_min (*big_it, *(big_it + 1));
			big_it += 2;
		}
}

void
Pmerge::merge_sort_pairs (std::vector<pair> &pairs)
{
	if (pairs.size () == 1)
		return;

	std::vector<pair> left (pairs.begin (),
							pairs.begin () + pairs.size () / 2);
	std::vector<pair> right (pairs.begin () + pairs.size () / 2, pairs.end ());

	merge_sort_pairs (left);
	merge_sort_pairs (right);

	merge (pairs, left, right);
}

void
Pmerge::merge (std::vector<pair> &pairs, std::vector<pair> &left,
			   std::vector<pair> &right)
{
	std::vector<pair>::iterator temp_it = pairs.begin ();
	std::vector<pair>::iterator left_it = left.begin ();
	std::vector<pair>::iterator right_it = right.begin ();

	while (left_it != left.end () && right_it != right.end ())
		{
			if ((*left_it)[MAIN] < (*right_it)[MAIN])
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
Pmerge::create_struggler (std::vector<int> &container, int &struggler)
{
	if (container.size () % 2)
		struggler = *(container.end () - 1);
	else
		struggler = 0;
}

void
Pmerge::create_main_chain (std::vector<pair> &pairs,
						   std::vector<int> &temp_container)
{
	for (std::vector<pair>::iterator it = pairs.begin (); it != pairs.end ();
		 it++)
		temp_container.push_back ((*it)[MAIN]);
}

void
Pmerge::insertion_sort_pairs (std::vector<pair> &pairs,
							  std::vector<int> &temp_container)
{
	std::vector<int> Jacobsthal (pairs.size ());
	JacobsthalSequence (Jacobsthal);

	for (size_t i = 0; i < Jacobsthal.size (); i++)
		{
			int search_range = Jacobsthal[i] - 1;
			for (int j = search_range; j > Jacobsthal[i - 1] - 1; j--)
				{
					if (j >= static_cast<int> (pairs.size ()))
						continue;
					int item_to_insert = pairs[j][PEND];
					std::vector<int>::iterator insert_position
						= binary_search (item_to_insert, search_range,
										 temp_container);
					temp_container.insert (insert_position, item_to_insert);
				}
		}
}

std::vector<int>::iterator
Pmerge::binary_search (int item_to_insert, int search_range,
					   std::vector<int> &temp_container)
{
	int starting_index = 0;

	while (starting_index <= search_range)
		{
			int middle_index = (starting_index + search_range) / 2;

			if (temp_container[middle_index] < item_to_insert)
				starting_index = middle_index + 1;
			else
				search_range = middle_index - 1;
		}

	return (temp_container.begin () + starting_index);
}

void
Pmerge::JacobsthalSequence (std::vector<int> &Jacobsthal)
{
	for (size_t i = 0; i < Jacobsthal.size (); i++)
		Jacobsthal[i] = (pow (2, i + 2) - pow (-1, i + 2)) / 3;
}

/*
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

void
Pmerge::merge (std::list<int> &container, std::list<int> &left,
			   std::list<int> &right)
{
	std::list<int>::iterator temp_it = container.begin ();
	std::list<int>::iterator left_it = left.begin ();
	std::list<int>::iterator right_it = right.begin ();

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
Pmerge::merge_container (std::list<int> &container)
{
	if (container.size () == 1)
		return;

	std::list<int>::iterator midpoint = container.begin ();
	std::advance (midpoint, container.size () / 2);

	std::list<int> left (container.begin (), midpoint);
	std::list<int> right (midpoint, container.end ());

	merge_container (left);
	merge_container (right);

	merge (container, left, right);
}
*/
