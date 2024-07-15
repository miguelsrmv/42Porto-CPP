#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T> class Array
{
  public:
	Array ();
	Array (unsigned int n);
	Array (const Array &copy);
	Array &operator= (const Array &copy);
	~Array ();

	T &operator[] (unsigned int n);
	unsigned int size () const;

  private:
	T *element_array;
	unsigned int array_length;
};

#endif
