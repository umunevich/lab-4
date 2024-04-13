#pragma once
#include "point.h"

struct Ray
{
	Point a = Point(0, 0);
	Point b = Point(0, 0);

	Ray(Point A, Point B);
};

Ray get_ray(Ray& R);