#pragma once
#include "ray.h"
#include "triangle.h"

namespace geometry
{
	bool equation(Point& A, Point& B, double& k, double& b);
	bool intersection(Ray& R, Point& t1, Point& t2);
	bool IsIntersect(Ray& R, Triangle& T);
} // namespace geometry