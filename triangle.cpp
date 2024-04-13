#include "triangle.h"
#include "point.h"
#include "geometry.h"
#include <iostream>

bool read(Point& a, Point& b, Point& c);
void readTriangle(Point& a, Point& b, Point& c);
bool isTriangle(Point& a, Point& b, Point& c);

Triangle::Triangle(Point A, Point B, Point C)
{
	a = A;
	b = B;
	c = C;
}

Triangle get_triangle(Triangle& T)
{
	readTriangle(T.a, T.b, T.c);
	return T;
}

bool read(Point& a, Point& b, Point& c)
{
	std::cout << "Enter the triangle:\n1: ";
	get_point(a);
	std::cout << "2: ";
	get_point(b);
	std::cout << "3: ";
	get_point(c);
	if ((a.x == b.x && a.y == b.y) || (b.x == c.x && b.y == c.y) || (a.x == c.x && a.y == c.y))
	{
		throw std::invalid_argument("Points are equal. Try again.");
		return false;
	}
	isTriangle(a, b, c);
	return true;
}

void readTriangle(Point& a, Point& b, Point& c)
{
	bool action = false;
	while (!action)
	{
		try
		{
			action = read(a, b, c);
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
bool isTriangle(Point& a, Point& b, Point& c)
{
	double k1, k2, k3, b1, b2, b3;
	geometry::equation(a, b, k1, b1);
	geometry::equation(b, c, k2, b2);
	geometry::equation(c, a, k3, b3);

	if (k1 == k2 || k2 == k3 || k3 == k1)
	{
		throw std::invalid_argument("It's not a triangle. Try again.");
		return false;
	}
	return true;
}