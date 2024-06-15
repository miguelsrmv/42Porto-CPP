#include "Point.hpp"

Point::Point () : x (0), y (0) {}

Point::Point (const float x_val, const float y_val) : x (x_val), y (y_val) {}

Point::Point (const Fixed &point) { *this = point; }

Point &
Point::operator= (const Point &copy)
{
	if (this == &copy)
		return (*this);
	/*
		Technically impossible to create this operator because x and y are
		consts as per the subject.
		As such, I decided not to change these variables!
		Possible alternatives:
			#1 Moving the assignment operator to "private" (against the rules?)
			#2 Casting away the consts (can lead to undefined behaviour)
				(Fixed) this->x = copy.get_x ();
				(Fixed) this->y = copy.get_y ();
			#3 Pointer shenanigans (can lead to undefined behaviour as well)
				*(Fixed *)&(this->x) = copy.get_x ();
				*(Fixed *)&(this->y) = copy.get_y ();
	*/
	return (*this);
}

Point::~Point () {}

Fixed
Point::get_x () const
{
	return (x);
}

Fixed
Point::get_y () const
{
	return (y);
}
