#include "geometry.h"

namespace geometry
{
	// Line equation
	bool equation(Point &A, Point &B, double& k, double& b)
	{
		k = (B.y - A.y) / (B.x - A.x);
		b = A.y - k * A.x;
		return true;
	}

	// True if lines are intersect,
	// False otherwise.
	bool intersection(Ray& R, Point& t1, Point& t2)
	{
		if (R.a.x == R.b.x && R.a.y != R.b.y)
		{
			double kt, bt;
			equation(t1, t2, kt, bt);
			double y = kt * R.a.x + bt;
			if ((R.a.y > R.b.y && R.a.y >= y && (R.a.x - t1.x) * (t2.x - R.a.x) >= 0
				&& (y - t1.y) * (t2.y - y) >= 0) || (R.a.y < R.b.y && R.a.y <= y
					&& (R.a.x - t1.x) * (t2.x - R.a.x) >= 0 && (y - t1.y) * (t2.y - y) >= 0))
			{
				return true;
			}
			return false;
		}
		else if (t1.x == t2.x && t1.y != t2.y)
		{
			double kr, br;
			equation(R.a, R.b, kr, br);
			double y = kr * t1.x + br;
			if ((t1.y > t2.y && t1.y >= y && y >= t2.y
				&& (t1.x - R.a.x) * (R.b.x - R.a.x) >= 0 (y - R.a.y) * (R.b.y - R.a.y) >= 0)
				|| (t1.y < t2.y && t1.y <= y && y <= t2.y
					&& (t1.x - R.a.x) * (R.b.x - R.a.x) >= 0 (y - R.a.y) * (R.b.y - R.a.y) >= 0))
			{
				return true;
			}
			return false;
		}
		else
		{
			double kr, br, kt, bt;
			equation(R.a, R.b, kr, br);
			equation(t1, t2, kt, bt);
			double x = (-1) * (br - bt) / (kr - kt);
			double y = kt * x + bt;
			if (kr != kt && (x - R.a.x) * (R.b.x - R.a.x) >= 0
				&& (y - R.a.y) * (R.b.y - R.a.y) >= 0 && (x - t1.x) * (t2.x - x) >= 0
				&& (y - t1.y) * (t2.y - y) >= 0)
			{
				return true;
			}
			return false;
		}
	}

	// True if ray intersect triangle.
	bool IsIntersect(Ray& R, Triangle& T)
	{
		if (intersection(R, T.a, T.b) ||
			intersection(R, T.b, T.c) ||
			intersection(R, T.c, T.a))
		{
			std::cout << "Yes, ray intersect triangle" << std::endl;
			return true;
		}
		std::cout << "No, ray doesn't intersect triangle" << std::endl;
		return false;
	}

} // namespace geometry