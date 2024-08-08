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

typedef std::vector<int> pair;

class Pmerge
{
  public:
	Pmerge ();
	Pmerge (const Pmerge &copy);
	const Pmerge &operator= (const Pmerge &copy);
	~Pmerge ();

	template <typename container> static double sort (container &cont);

  private:
	static double get_time_diff (timeval start_time, timeval end_time);
	static int get_max (int a, int b);
	static int get_min (int a, int b);

	// For std::vector<int>
	static void Ford_Johnson (std::vector<int> &container);
	static void create_pairs (std::vector<int> &container,
							  std::vector<pair> &pairs);
	static void merge_sort_pairs (std::vector<pair> &pairs);
	static void create_struggler (std::vector<int> &container, int &struggler);
	static void merge (std::vector<pair> &pairs, std::vector<pair> &left,
					   std::vector<pair> &right);
	static void create_main_chain (std::vector<pair> &pairs,
								   std::vector<int> &temp_container);

	static void insertion_sort_pairs (std::vector<pair> &pairs,
									  std::vector<int> &temp_container);
	static void JacobsthalSequence (std::vector<int> &Jacobsthal);
	static std::vector<int>::iterator
	binary_search (int item_to_insert, int search_range,
				   std::vector<int> &temp_container);
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
