#pragma once
#include "point.h"

struct Triangle
{
	Point a = Point(0, 0);
	Point b = Point(0, 0);
	Point c = Point(0, 0);

	Triangle(Point A, Point B, Point C);
};

Triangle get_triangle(Triangle& T);