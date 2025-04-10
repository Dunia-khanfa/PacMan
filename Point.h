#pragma once

class Point
{
	int x;
	int y;

public:
	Point(int _x, int _y) : x(_x), y(_y) { }

	Point(const Point& p) { x = p.x; y = p.y; }

	bool operator==(const Point& other);

	int get_X() const { return x; }

	int get_Y() const { return y; }

	void set_X(int _x);

	void set_Y(int _y);

	void set(int _x, int _y);
};