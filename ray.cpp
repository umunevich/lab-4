#include "ray.h"

bool read(Point& a, Point& b);
void readRay(Point& a, Point& b);

Ray::Ray(Point A, Point B)
{
	a = A;
	b = B;
}

Ray get_ray(Ray& R)
{
	readRay(R.a, R.b);
	return R;
}

bool read(Point& a, Point& b)
{
	std::cout << "Enter the ray:\nStart point: ";
	get_point(a);
	std::cout << "End point: ";
	get_point(b);
	if (a.x == b.x && a.y == b.y)
	{
		throw std::invalid_argument("Points are equal. Try again.");
		return false;
	}
	return true;
}

// Multople times read ray.
void readRay(Point& a, Point& b)
{
	bool action = false;
	while (!action)
	{
		try
		{
			action = read(a, b);
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}