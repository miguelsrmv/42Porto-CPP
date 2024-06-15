#include "Point.hpp"

Point::Point () : x (0), y (0) {}

Point::Point (const float x_val, const float y_val) : x (x_val), y (y_val) {}

Point::Point (const Fixed &point) { *this = point; }

Point &
Point::operator= (const Point &copy)
{
	if (this == &copy)
		return (*this);
	(Fixed) this->x = copy.get_x ();
	(Fixed) this->y = copy.get_y ();
	return (*this);
}

Point::~Point () {}

Fixed
Point::get_x () const
{
	return ((Fixed)this->x);
}

Fixed
Point::get_y () const
{
	return ((Fixed)this->y);
}
