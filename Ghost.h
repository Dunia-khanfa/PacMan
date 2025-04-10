#pragma once
#include "Point.h"
#include "Board.h"
#include "Utilities.h"
#include <windows.h> // for Sleep()
#include <vector>

class Ghost
{
	char direction;
	Point place;
	bool onDot;

public:
	Ghost(int startX, int startY) : direction(Utilities::STAY), place(startX, startY), onDot(false) { }

	Ghost(const Ghost&) = delete;

	Point getPlace() const { return place; }

	void setPlace(const Point& p, const Board& b, bool& wasPac);

	// gets whether or not the ghost is on dot- to make sure the ghost "floats" and not eat the dot
	bool getOnDot() const { return onDot; }

	// checks if the ghost can move in the same direction and if certain time hadn't passed
	// if so, moves the ghost according to said direction
	// if not, checks what direction can the ghost move to and select one of those directions randomly and moves the ghost there
	void move(const Point& point_of_pac, const Board& board, int time, bool& wasPac);

	// returns true if there is not a wall and not another ghost and the ghost can move, false otherwise
	bool canMove(int x, int y, const Board& b);

	// returns the point to which the ghost moves to based on her direction
	Point next();
};