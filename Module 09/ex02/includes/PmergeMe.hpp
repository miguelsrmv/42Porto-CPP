#ifndef PMERGE_HPP
#define PMERGE_HPP

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

	static double merge (std::vector<int> container);
	static double merge (std::deque<int> container);

  private:
	static double get_time_diff (timeval start_time, timeval end_time);

	static void merge_container (std::vector<int> container);
	static void merge_container (std::deque<int> container);
};

#endif
