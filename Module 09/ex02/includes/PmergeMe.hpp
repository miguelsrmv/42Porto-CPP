#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <cmath>
#include <cstddef>
#include <deque>
#include <list>
#include <sys/time.h>
#include <vector>

#define MAIN 0
#define PEND 1

typedef std::vector<int> pair_vector;
typedef std::list<int> pair_list;

class Pmerge
{
  public:
	Pmerge ();
	Pmerge (const Pmerge &copy);
	const Pmerge &operator= (const Pmerge &copy);
	~Pmerge ();

	static bool there_are_duplicates (std::vector<int> &container);
	static bool there_are_duplicates (std::list<int> &container);
	template <typename container> static double sort (container &cont);

  private:
	static double get_time_diff (timeval start_time, timeval end_time);
	static int get_max (int a, int b);
	static int get_min (int a, int b);

	// For std::vector<int>
	static void Ford_Johnson (std::vector<int> &container);
	static void create_pairs (std::vector<int> &container,
							  std::vector<pair_vector> &pair_vectors);
	static void merge_sort_pairs (std::vector<pair_vector> &pair_vectors);
	static void create_struggler (std::vector<int> &container, int &struggler);
	static void merge (std::vector<pair_vector> &pair_vectors,
					   std::vector<pair_vector> &left,
					   std::vector<pair_vector> &right);
	static void create_main_chain (std::vector<pair_vector> &pair_vectors,
								   std::vector<int> &temp_container);

	static void insertion_sort_pairs (std::vector<pair_vector> &pair_vectors,
									  std::vector<int> &temp_container);
	static void JacobsthalSequence (std::vector<int> &Jacobsthal);
	static std::vector<int>::iterator
	binary_search (int item_to_insert, int search_range,
				   std::vector<int> &temp_container);

	// For std::list<int>
	static void Ford_Johnson (std::list<int> &container);
	static void create_pairs (std::list<int> &container,
							  std::list<pair_list> &pair_lists);
	static void merge_sort_pairs (std::list<pair_list> &pair_lists);
	static void create_struggler (std::list<int> &container, int &struggler);
	static void merge (std::list<pair_list> &pair_lists,
					   std::list<pair_list> &left,
					   std::list<pair_list> &right);
	static void create_main_chain (std::list<pair_list> &pair_lists,
								   std::list<int> &temp_container);

	static void insertion_sort_pairs (std::list<pair_list> &pair_lists,
									  std::list<int> &temp_container);
	static void JacobsthalSequence (std::list<int> &Jacobsthal);
	static std::list<int>::iterator
	binary_search (int item_to_insert, int search_range,
				   std::list<int> &temp_container);
};

template <typename container>
double
Pmerge::sort (container &cont)
{
	timeval start_time;
	gettimeofday (&start_time, NULL);

	Ford_Johnson (cont);

	timeval end_time;
	gettimeofday (&end_time, NULL);

	return (get_time_diff (start_time, end_time));
}

#endif
