#include "Point.hpp"

bool
bsp (Point const a, Point const b, Point const c, Point const point)
{
	float denominator;
	float coord_a;
	float coord_b;
	float coord_c;

	denominator = ((b.get_y () - c.get_y ()) * (a.get_x () - c.get_x ())
				   + (c.get_x () - b.get_x ()) * (a.get_y () - c.get_y ()));

	coord_a = ((b.get_y () - c.get_y ()) * (point.get_x () - c.get_x ())
			   + (c.get_x () - b.get_x ()) * (point.get_y () - c.get_y ()))
			  / denominator;

	coord_b = ((c.get_y () - a.get_y ()) * (point.get_x () - c.get_x ())
			   + (a.get_x () - c.get_x ()) * (point.get_y () - c.get_y ()))
			  / denominator;

	coord_c = 1.0f - coord_a - coord_b;

	return (coord_a >= 0 && coord_b >= 0 && coord_c >= 0);
}
