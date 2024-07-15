#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <class T>
void iter (T *array_address, std::size_t length, void (*f) (T));

template <class T> void f (T value);

#endif
