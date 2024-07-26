#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
  public:
	MutantStack ();
	MutantStack (const MutantStack &copy);
	const MutantStack &operator= (const MutantStack &copy);
	~MutantStack ();

	typedef typename C::iterator iterator;

	iterator begin (void);
	iterator end (void);
};

#include "MutantStack.tpp"

#endif
