// vim: set filetype=cpp :

#include "Array.hpp"
#include <cstddef>

template <class T> Array<T>::Array () : array_length (0)
{
	element_array = new T[array_length];
}

template <class T> Array<T>::Array (unsigned int n) : array_length (n)
{
	element_array = new T[array_length];
	for (unsigned int i = 0; i < n; i++)
		element_array[i] = T ();
}

template <class T> Array<T>::Array (const Array &copy)
{
	element_array = NULL;
	*this = copy;
}

template <class T>
Array<T> &
Array<T>::operator= (const Array<T> &copy)
{
	if (this != &copy)
		{
			this->array_length = copy.size ();
			delete[] this->element_array;
			this->element_array = new T[this->array_length];
			for (unsigned int i = 0; i < this->array_length; i++)
				this->element_array[i] = copy.element_array[i];
		}
	return (*this);
}

template <class T> Array<T>::~Array () { delete[] element_array; }

template <class T>
T &
Array<T>::operator[] (unsigned int n)
{
	return element_array[n];
}

template <class T>
unsigned int
Array<T>::size () const
{
	return array_length;
}
