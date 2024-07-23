#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>

class Span
{
  public:
	Span (unsigned int n);
	Span (const Span &copy);
	const Span &operator= (const Span &copy);
	~Span ();

	void addNumber (int number);
	void fill_in_span ();
	unsigned int shortestSpan ();
	unsigned int longestSpan ();

	unsigned int get_max_length () const;
	unsigned int get_curr_length () const;
	std::vector<int> get_storage () const;

	class TooManyNumbersAdded : public std::exception
	{
	  public:
		const char *what () const throw ();
	};
	class NotEnoughNumbersStored : public std::exception
	{
	  public:
		const char *what () const throw ();
	};

  private:
	unsigned int _maximum_length;
	unsigned int _current_length;

	std::vector<int> _storage;
};

std::ostream &operator<< (std::ostream &outstream, const Span &copy);

#endif
