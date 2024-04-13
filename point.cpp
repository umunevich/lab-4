#include "point.h"
#include <iostream>
void readPoint(double& x, double& y);
bool read(double& x, double& y);

Point::Point(double X, double Y)
	: x(0), y(0)
{
	x = X;
	y = Y;
}

// Init point
Point get_point(Point &A)
{
	double x, y;
	readPoint(x, y);
	return A = Point(x, y);
}

// One-time read point
bool read(double &x, double &y)
{
	std::cout << "Enter point as X and Y coords:" << std::endl;
	if (std::cin >> x >> y)
	{ 
		return true;
	}
	std::cin.clear();
	std::cin.ignore();
	throw std::invalid_argument("Wrond input.");
	return false;
}

// Multiple times read point.
void readPoint(double &x, double &y)
{
	bool action = false;
	while (!action)
	{
		try
		{
			action = read(x, y);
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}