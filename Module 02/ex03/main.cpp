#include "Point.hpp"

bool bsp (Point const a, Point const b, Point const c, Point const point);

void
print_triangle (const Point a, const Point b, const Point c)
{
	std::cout << "Triangle [(" << a.get_x () << " , " << a.get_y () << "), ("
			  << b.get_x () << " , " << b.get_y () << "), (" << c.get_x ()
			  << " , " << c.get_y () << ")] : ";
}

void
print_point_location (bool point_is_inside_triangle, Point const point)
{
	std::string location;
	if (point_is_inside_triangle)
		location = " INSIDE ";
	else
		location = " OUTSIDE ";

	std::cout << "Point (" << point.get_x () << " , " << point.get_y ()
			  << ") is" << location << "the triangle!" << std::endl
			  << std::endl;
}

// Regular triangle, point is inside
void
test_case_1 ()
{
	const Point a (5.0f, 0.0f);
	const Point b (2.5f, 5.0f);
	const Point c (0.0f, 0.0f);
	const Point point (2.5f, 2.5f);

	print_triangle (a, b, c);
	print_point_location (bsp (a, b, c, point), point);
}

// Triangle with negative coordinates, point is inside
void
test_case_2 ()
{
	const Point a (-4.0f, -2.0f);
	const Point b (-1.5f, 15.0f);
	const Point c (4.0f, -1);
	const Point point (0.0f, 0.0f);

	print_triangle (a, b, c);
	print_point_location (bsp (a, b, c, point), point);
}

// Point super position, point is on top of vertex (thus, inside)
void
test_case_3 ()
{
	const Point a (5.0f, 0.0f);
	const Point b (2.5f, 5.0f);
	const Point c (0.0f, 0.0f);
	const Point point (2.5f, 5.0f);

	print_triangle (a, b, c);
	print_point_location (bsp (a, b, c, point), point);
}

// Point is on-line (thus inside)
void
test_case_4 ()
{
	const Point a (-4.0f, 0.0f);
	const Point b (0.0f, 4.0f);
	const Point c (4.0f, 0.0f);
	const Point point (2.0f, 2.0f);

	print_triangle (a, b, c);
	print_point_location (bsp (a, b, c, point), point);
}

// Degenerated triangle and point is on-line (outside because triangle has no
// area)
void
test_case_5 ()
{
	const Point a (-5.0f, -5.0f);
	const Point b (0.0f, 0.0f);
	const Point c (5.0f, 5.0f);
	const Point point (0.0f, 0.0f);

	print_triangle (a, b, c);
	print_point_location (bsp (a, b, c, point), point);
}

int
main (void)
{
	test_case_1 ();
	test_case_2 ();
	test_case_3 ();
	test_case_4 ();
	test_case_5 ();
	return (0);
}
