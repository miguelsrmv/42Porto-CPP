#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

// Constructors and Destructors
Span::Span (unsigned int n) : _maximum_length (n), _current_length (0) {}

Span::Span (const Span &copy) { *this = copy; }

const Span &
Span::operator= (const Span &copy)
{
	if (this != &copy)
		{
			this->_maximum_length = copy._maximum_length;
			this->_current_length = copy._current_length;
			this->_storage = copy._storage;
		}
	return (*this);
}

Span::~Span () {}

// Subject functions
void
Span::addNumber (int number)
{
	if (_current_length == _maximum_length)
		throw Span::TooManyNumbersAdded ();
	_current_length++;
	_storage.push_back (number);
}

int
rand_int ()
{
	return rand ();
}

void
Span::fill_in_span ()
{
	_storage.resize (_maximum_length);
	std::generate (_storage.begin () + _current_length, _storage.end (),
				   rand_int);
	_current_length = _maximum_length;
}

unsigned int
Span::shortestSpan ()
{
	if (_current_length < 2)
		throw Span::NotEnoughNumbersStored ();

	std::vector<int> sorted_storage = _storage;
	std::sort (sorted_storage.begin (), sorted_storage.end ());

	unsigned int distance = std::numeric_limits<unsigned int>::max ();

	for (std::vector<int>::iterator it = sorted_storage.begin ();
		 it < sorted_storage.end () - 1; it++)
		{
			unsigned int temp_distance
				= static_cast<unsigned int> (*(it + 1) - *it);
			if (temp_distance < distance)
				distance = temp_distance;
		}

	return (distance);
}

unsigned int
Span::longestSpan ()
{
	if (_current_length < 2)
		throw Span::NotEnoughNumbersStored ();

	std::vector<int>::iterator it_max
		= std::max_element (_storage.begin (), _storage.end ());
	std::vector<int>::iterator it_min
		= std::min_element (_storage.begin (), _storage.end ());

	return (*it_max - *it_min);
}

// Helper functions
unsigned int
Span::get_max_length () const
{
	return _maximum_length;
}

unsigned int
Span::get_curr_length () const
{
	return _current_length;
}

std::vector<int>
Span::get_storage () const
{
	return _storage;
}

// Exceptions
const char *
Span::TooManyNumbersAdded::what () const throw ()
{
	return "Error: Too many numbers added";
}

const char *
Span::NotEnoughNumbersStored::what () const throw ()
{
	return "Error: Not enough numbers stored in span";
}

// Extra output function
std::ostream &
operator<< (std::ostream &outstream, const Span &copy)
{
	outstream << "Vector current size: [" << copy.get_curr_length () << "]"
			  << std::endl;
	outstream << "Vector max size: [" << copy.get_max_length () << "]"
			  << std::endl;

	std::vector<int> vector = copy.get_storage ();

	outstream << "Vector contents: {";
	for (std::vector<int>::iterator it = vector.begin (); it != vector.end ();
		 it++)
		{
			outstream << *it;
			if ((it + 1) != vector.end ())
				outstream << ",";
		}
	outstream << "}" << std::endl << std::endl;

	return outstream;
}
