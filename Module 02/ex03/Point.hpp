#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
  public:
	Point ();
	Point (const float x_val, const float y_val);
	Point (const Fixed &point);
	Point &operator= (const Point &copy);
	~Point ();
	Fixed get_x () const;
	Fixed get_y () const;

  private:
	const Fixed x;
	const Fixed y;
};

#endif
