#include "Ghost.h"

void Ghost::setPlace(const Point& p, const Board& b, bool& wasPac)
{
	if (onDot)
		Utilities::printCharToBoard(place, Utilities::DOT_SIGN);
	else
		Utilities::printCharToBoard(place, Utilities::SPACE_SIGN);

	place = p;

	char c = b.getPoint(place);

	if (c == Utilities::DOT_SIGN)
	{
		onDot = true;
	}
	else
	{
		onDot = false;
	}
	if (c == Utilities::PAC_SIGN)
	{
		wasPac = true;
	}

	Utilities::printCharToBoard(place, Utilities::GHOST_SIGN);
}

void Ghost::move(const Point& point_of_pac, const Board& board, int time, bool& wasPac)
{
	Point p(next());
	if ((canMove(p.get_X(), p.get_Y(), board)) && (direction != Utilities::STAY) && (time % 20 != 0))
	{
		setPlace(p, board, wasPac);
		return;
	}

	std::vector<int> v;

	if (((board.get(place.get_X(), place.get_Y() - 1)) != Utilities::WALL_SIGN) && ((board.get(place.get_X(), place.get_Y() - 1)) != Utilities::GHOST_SIGN))
	{
		v.push_back(0); //up
	}
	if (((board.get(place.get_X(), place.get_Y() + 1)) != Utilities::WALL_SIGN) && ((board.get(place.get_X(), place.get_Y() + 1)) != Utilities::GHOST_SIGN))
	{
		v.push_back(1); //down
	}
	if (((board.get(place.get_X() + 1, place.get_Y())) != Utilities::WALL_SIGN) && ((board.get(place.get_X() + 1, place.get_Y())) != Utilities::GHOST_SIGN))
	{
		v.push_back(2); //right
	}
	if (((board.get(place.get_X() - 1, place.get_Y())) != Utilities::WALL_SIGN) && ((board.get(place.get_X() - 1, place.get_Y())) != Utilities::GHOST_SIGN))
	{
		v.push_back(3); //left
	}

	bool done = false;
	int random = rand() % 4;
	while (!done)
	{
		for (const int& i : v)
		{
			if (i == random)
			{
				done = true;
				break;
			}
		}
		if (!done)
			random = rand() % 4;
	}

	switch (random)
	{
	case 0:
		direction = Utilities::UP;
		break;
	case 1:
		direction = Utilities::DOWN;
		break;
	case 2:
		direction = Utilities::RIGHT;
		break;
	case 3:
		direction = Utilities::LEFT;
		break;
	}

	p = next();
	setPlace(p, board, wasPac);
}


bool Ghost::canMove(int x, int y, const Board& b)
{
	return ((b.get(x, y) != Utilities::WALL_SIGN) && (b.get(x, y) != Utilities::GHOST_SIGN));
}

Point Ghost::next()
{
	Point p(place);

	switch (direction)
	{
	case Utilities::UP:
		p.set_Y(place.get_Y() - 1);
		// for making the ghost walk at a normal speed even walking up/down where the distance between spaces is smaller then when walking right/left
		Sleep(30);
		break;
	case Utilities::DOWN:
		p.set_Y(place.get_Y() + 1);
		Sleep(30);
		break;
	case Utilities::RIGHT:
		Sleep(10);
		p.set_X(place.get_X() + 1);
		break;
	case Utilities::LEFT:
		Sleep(10);
		p.set_X(place.get_X() - 1);
		break;
	}

	return p;
}