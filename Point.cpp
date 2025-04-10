#include "Point.h"

void Point::set_X(int _x)
{
	if (_x >= 0 && _x < 80)
		x = _x;
}

void Point::set_Y(int _y)
{
	if (_y >= 0 && _y < 24)
		y = _y;
}

void Point::set(int _x, int _y)
{
	if (_x >= 0 && _x < 80)
		x = _x;
	if (_y >= 0 && _y < 24)
		y = _y;
}

bool Point::operator==(const Point& other)
{
	return (x == other.x && y == other.y);
}

