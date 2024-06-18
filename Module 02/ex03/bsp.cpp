#include "Point.hpp"

bool is_on_vertex(float lambda_1, float lambda_2, float lambda_3)
{
	return (lambda_1 == 1.0f || lambda_2 == 1.0f || lambda_3 == 1.0f);
}

bool is_on_line(float lambda_1, float lambda_2, float lambda_3)
{
	return (lambda_1 == 0.0f || lambda_2 == 0.0f || lambda_3 == 0.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float denominator;
	float lambda_1;
	float lambda_2;
	float lambda_3;

	denominator = ((b.get_y() - c.get_y()) * (a.get_x() - c.get_x()) + (c.get_x() - b.get_x()) * (a.get_y() - c.get_y()));

	lambda_1 = ((b.get_y() - c.get_y()) * (point.get_x() - c.get_x()) + (c.get_x() - b.get_x()) * (point.get_y() - c.get_y())) / denominator;

	lambda_2 = ((c.get_y() - a.get_y()) * (point.get_x() - c.get_x()) + (a.get_x() - c.get_x()) * (point.get_y() - c.get_y())) / denominator;

	lambda_3 = 1.0f - lambda_1 - lambda_2;

	if (is_on_vertex(lambda_1, lambda_2, lambda_3) || is_on_line(lambda_1, lambda_2, lambda_3))
		return (false);

	return (lambda_1 > 0 && lambda_2 > 0 && lambda_3 > 0);
}

