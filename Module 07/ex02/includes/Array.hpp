#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array
{
  public:
	Array ();
	Array (unsigned int n);
	Array (const Array &copy);
	const Array &operator= (const Array &copy);
	T &operator[] (unsigned int position);
	~Array ();

	unsigned int size ();

	class OutOfBoundsException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};

  private:
	unsigned int _array_length;

	T *_array;
};

#include "Array.tpp"

#endif
