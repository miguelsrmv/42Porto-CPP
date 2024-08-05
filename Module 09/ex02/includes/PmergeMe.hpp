#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <cstddef>
#include <deque>
#include <sys/time.h>
#include <vector>

class Pmerge
{
  public:
	Pmerge ();
	Pmerge (const Pmerge &copy);
	const Pmerge &operator= (const Pmerge &copy);
	~Pmerge ();

	template <typename container> static double merge (container &cont);

  private:
	static double get_time_diff (timeval start_time, timeval end_time);

	static void merge_container (std::vector<int> &container);
	static void merge_container (std::deque<int> &container);

	static void merge (std::vector<int> &container, std::vector<int> &left,
					   std::vector<int> &right);
	static void merge (std::deque<int> &container, std::deque<int> &left,
					   std::deque<int> &right);
};

template <typename container>
double
Pmerge::merge (container &cont)
{
	timeval start_time;
	gettimeofday (&start_time, NULL);

	merge_container (cont);

	timeval end_time;
	gettimeofday (&end_time, NULL);

	return (get_time_diff (start_time, end_time));
}

#endif
