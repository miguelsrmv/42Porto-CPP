// vim: set filetype=cpp:

#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack () : std::stack<T, C> ()
{
}

template <typename T, typename C>
MutantStack<T, C>::MutantStack (const MutantStack &copy) : std::stack<T, C> ()
{
	*this = copy;
}

template <typename T, typename C>
const MutantStack<T, C> &
MutantStack<T, C>::operator= (const MutantStack &copy)
{
	if (this != &copy)
		{
			;
		}
	return *this;
}

template <typename T, typename C> MutantStack<T, C>::~MutantStack () {}

template <typename T, typename C>
typename MutantStack<T, C>::iterator
MutantStack<T, C>::begin ()
{
	return this->c.begin ();
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator
MutantStack<T, C>::end ()
{
	return this->c.end ();
}
