#pragma once
#include <iostream>

struct Point
{
	double x, y;
	Point(double x, double y);
};

Point get_point(Point &A);