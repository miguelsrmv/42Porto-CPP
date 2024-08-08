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

// For std::vector<int>
void
Pmerge::Ford_Johnson (std::vector<int> &container)
{

	if (container.size () == 1)
		return;

	std::vector<pair_vector> pairs;
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
				struggler, temp_container.size () - 1, temp_container);
			temp_container.insert (final_insertion, struggler);
		}

	container = temp_container;
}

void
Pmerge::create_pairs (std::vector<int> &container,
					  std::vector<pair_vector> &pairs)
{
	int pairs_size = container.size () / 2;

	pairs.resize (pairs_size);
	pairs.assign (pairs_size, std::vector<int> (2));

	std::vector<int>::iterator big_it = container.begin ();

	for (std::vector<pair_vector>::iterator small_it = pairs.begin ();
		 small_it != pairs.end (); small_it++)
		{
			(*small_it)[MAIN] = get_max (*big_it, *(big_it + 1));
			(*small_it)[PEND] = get_min (*big_it, *(big_it + 1));
			big_it += 2;
		}
}

void
Pmerge::merge_sort_pairs (std::vector<pair_vector> &pairs)
{
	if (pairs.size () == 1)
		return;

	std::vector<pair_vector> left (pairs.begin (),
								   pairs.begin () + pairs.size () / 2);
	std::vector<pair_vector> right (pairs.begin () + pairs.size () / 2,
									pairs.end ());

	merge_sort_pairs (left);
	merge_sort_pairs (right);

	merge (pairs, left, right);
}

void
Pmerge::merge (std::vector<pair_vector> &pairs, std::vector<pair_vector> &left,
			   std::vector<pair_vector> &right)
{
	std::vector<pair_vector>::iterator temp_it = pairs.begin ();
	std::vector<pair_vector>::iterator left_it = left.begin ();
	std::vector<pair_vector>::iterator right_it = right.begin ();

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
Pmerge::create_main_chain (std::vector<pair_vector> &pairs,
						   std::vector<int> &temp_container)
{
	for (std::vector<pair_vector>::iterator it = pairs.begin ();
		 it != pairs.end (); it++)
		temp_container.push_back ((*it)[MAIN]);
}

void
Pmerge::insertion_sort_pairs (std::vector<pair_vector> &pairs,
							  std::vector<int> &temp_container)
{
	std::vector<int> Jacobsthal (pairs.size ());
	JacobsthalSequence (Jacobsthal);

	int insertion_count = 0;

	for (size_t i = 0; i < Jacobsthal.size (); i++)
		{
			int search_range = Jacobsthal[i] - 1;
			int prev_range = (i > 0) ? Jacobsthal[i - 1] - 1 : -1;

			if (search_range >= static_cast<int> (pairs.size ()))
				search_range = pairs.size () - 1;

			for (int j = Jacobsthal[i] - 1; j > prev_range; j--)
				{
					if (j >= static_cast<int> (pairs.size ()))
						j = pairs.size () - 1;
					int item_to_insert = pairs[j][PEND];
					std::vector<int>::iterator insert_position
						= binary_search (item_to_insert,
										 search_range + insertion_count,
										 temp_container);
					temp_container.insert (insert_position, item_to_insert);
					insertion_count++;
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

// For std::list<int>
void
Pmerge::Ford_Johnson (std::list<int> &container)
{

	if (container.size () == 1)
		return;

	std::list<pair_list> pairs;
	create_pairs (container, pairs);
	merge_sort_pairs (pairs);

	int struggler;
	create_struggler (container, struggler);

	std::list<int> temp_container;
	create_main_chain (pairs, temp_container);

	insertion_sort_pairs (pairs, temp_container);

	if (struggler)
		{
			std::list<int>::iterator final_insertion = binary_search (
				struggler, temp_container.size () - 1, temp_container);
			temp_container.insert (final_insertion, struggler);
		}

	container = temp_container;
}

void
Pmerge::create_pairs (std::list<int> &container, std::list<pair_list> &pairs)
{
	int pairs_size = container.size () / 2;

	pairs.resize (pairs_size);
	pairs.assign (pairs_size, std::list<int> (2));

	std::list<int>::iterator big_it = container.begin ();

	for (std::list<pair_list>::iterator small_it = pairs.begin ();
		 small_it != pairs.end (); small_it++)
		{
			std::list<int>::iterator big_it_next = big_it;
			std::advance (big_it_next, 1);
			(*small_it).front () = get_max (*big_it, *big_it_next);
			(*small_it).back () = get_min (*big_it, *big_it_next);
			std::advance (big_it, 2);
		}
}

void
Pmerge::merge_sort_pairs (std::list<pair_list> &pairs)
{
	if (pairs.size () == 1)
		return;

	std::list<pair_list>::iterator mid = pairs.begin ();
	std::advance (mid, pairs.size () / 2);

	std::list<pair_list> left (pairs.begin (), mid);
	std::list<pair_list> right (mid, pairs.end ());

	merge_sort_pairs (left);
	merge_sort_pairs (right);

	merge (pairs, left, right);
}

void
Pmerge::merge (std::list<pair_list> &pairs, std::list<pair_list> &left,
			   std::list<pair_list> &right)
{
	std::list<pair_list>::iterator temp_it = pairs.begin ();
	std::list<pair_list>::iterator left_it = left.begin ();
	std::list<pair_list>::iterator right_it = right.begin ();

	while (left_it != left.end () && right_it != right.end ())
		{
			if ((*left_it).front () < (*right_it).front ())
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
Pmerge::create_struggler (std::list<int> &container, int &struggler)
{
	if (container.size () % 2)
		{
			std::list<int>::iterator before_end = container.end ();
			std::advance (before_end, -1);
			struggler = *before_end;
		}
	else
		struggler = 0;
}

void
Pmerge::create_main_chain (std::list<pair_list> &pairs,
						   std::list<int> &temp_container)
{
	for (std::list<pair_list>::iterator it = pairs.begin ();
		 it != pairs.end (); it++)
		temp_container.push_back ((*it).front ());
}

void
Pmerge::insertion_sort_pairs (std::list<pair_list> &pairs,
							  std::list<int> &temp_container)
{
	std::list<int> Jacobsthal (pairs.size ());
	JacobsthalSequence (Jacobsthal);

	int insertion_count = 0;

	for (size_t i = 0; i < Jacobsthal.size (); i++)
		{
			std::list<int>::iterator Jacobsthal_iterator = Jacobsthal.begin ();
			std::advance (Jacobsthal_iterator, i);

			std::list<int>::iterator Prev_Jacobsthal_iterator
				= Jacobsthal_iterator;
			std::advance (Prev_Jacobsthal_iterator, -1);

			int search_range = *Jacobsthal_iterator - 1;
			int prev_range = (i > 0) ? (*Prev_Jacobsthal_iterator) - 1 : -1;

			if (search_range >= static_cast<int> (pairs.size ()))
				search_range = pairs.size () - 1;

			for (int j = *Jacobsthal_iterator - 1; j > prev_range; j--)
				{
					if (j >= static_cast<int> (pairs.size ()))
						j = pairs.size () - 1;

					std::list<pair_list>::iterator pairs_iterator
						= pairs.begin ();
					std::advance (pairs_iterator, j);
					int item_to_insert = (*pairs_iterator).back ();
					std::list<int>::iterator insert_position = binary_search (
						item_to_insert, search_range + insertion_count,
						temp_container);
					temp_container.insert (insert_position, item_to_insert);
					insertion_count++;
				}
		}
}

std::list<int>::iterator
Pmerge::binary_search (int item_to_insert, int search_range,
					   std::list<int> &temp_container)
{
	std::list<int>::iterator left = temp_container.begin ();
	std::list<int>::iterator right = temp_container.begin ();
	std::advance (right, search_range);

	while (left != right)
		{
			std::list<int>::iterator mid = left;
			std::advance (mid, std::distance (mid, right) / 2);

			if (*mid < item_to_insert)
				left = ++mid;
			else
				right = mid;
		}

	return (left);
}

void
Pmerge::JacobsthalSequence (std::list<int> &Jacobsthal)
{
	for (std::list<int>::iterator i = Jacobsthal.begin ();
		 i != Jacobsthal.end (); i++)
		{
			int distance = std::distance (Jacobsthal.begin (), i);
			*i = (pow (2, distance + 2) - pow (-1, distance + 2)) / 3;
		}
}
