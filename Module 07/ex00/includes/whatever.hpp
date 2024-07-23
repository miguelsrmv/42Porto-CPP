#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void
swap (T &value_1, T &value_2)
{
	T temp = value_2;
	value_2 = value_1;
	value_1 = temp;
}

template <typename T>
T
min (T value_1, T value_2)
{
	if (value_1 < value_2)
		return (value_1);
	return (value_2);
}

template <typename T>
T
max (T value_1, T value_2)
{
	if (value_1 > value_2)
		return (value_1);
	return (value_2);
}

#endif
