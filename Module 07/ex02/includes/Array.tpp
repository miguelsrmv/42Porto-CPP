// vim: set filetype=cpp :

#include "Array.hpp"

template <typename T> Array<T>::Array () : _array_length (0)
{
	_array = new T[0];
}

template <typename T> Array<T>::Array (unsigned int n) : _array_length (n)
{
	_array = new T[_array_length];
}

template <typename T>
Array<T>::Array (const Array &copy) : _array_length (copy._array_length)
{
	_array = new T[_array_length];
	for (unsigned int i = 0; i < _array_length; i++)
		_array[i] = copy._array[i];
}

template <typename T>
const Array<T> &
Array<T>::operator= (const Array &copy)
{
	if (this != &copy)
		{
			delete[] _array;
			_array_length = copy._array_length;
			_array = new T[_array_length];
			for (unsigned int i = 0; i < _array_length; i++)
				_array[i] = copy._array[i];
		}
	return (*this);
}

template <typename T>
T &
Array<T>::operator[] (unsigned int position)
{
	if (position >= _array_length)
		throw OutOfBoundsException ();
	return (_array[position]);
}

template <typename T> Array<T>::~Array () { delete[] _array; }

template <typename T>
unsigned int
Array<T>::size ()
{
	return _array_length;
}

template <typename T>
const char *
Array<T>::OutOfBoundsException::what () const throw ()
{
	return "Error: Out of bounds!";
}
