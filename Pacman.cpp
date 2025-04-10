#include "Pacman.h"

void Pacman::setPlace(const Board& b, bool& wasDot, bool& wasGhost, const Point& p)
{
	Utilities::printCharToBoard(place, Utilities::SPACE_SIGN);

	place = p;

	char c = b.getPoint(place);

	Utilities::printCharToBoard(place, Utilities::PAC_SIGN);

	if (c == Utilities::DOT_SIGN)
	{
		eatADot();
		wasDot = true;
		Utilities::updateInfoLine(Utilities::X_OF_SCORE_IN_INFO_LINE, points);
	}
	else if (c == Utilities::GHOST_SIGN)
	{
		getEaten();
		wasGhost = true;
		Utilities::updateInfoLine(Utilities::X_OF_LIVES_IN_INFO_LINE, lives);
	}
}

bool Pacman::move(const Board& b, bool& wasDot, bool& wasGhost)
{
	char past_direction = direction;
	bool pause_game = false;

	if (_kbhit())
	{
		direction = _getch();
		direction = toupper(direction);
		if ((direction != Utilities::UP) && (direction != Utilities::DOWN) && (direction != Utilities::RIGHT) && (direction != Utilities::LEFT) && (direction != Utilities::STAY))
		{
			if (direction == Utilities::ASCII_OF_ESC)
				pause_game = true;
			direction = past_direction;
		}
	}

	if (pause_game)
		return true;

	Point p = next();

	if (canMove(p, b))
		setPlace(b, wasDot, wasGhost, p);

	return false;
}

bool Pacman::canMove(const Point& p, const Board& b) const
{
	return (b.get(p.get_X(), p.get_Y()) != Utilities::WALL_SIGN);
}

Point Pacman::next()
{
	Point p(place);

	switch (direction)
	{
	case Utilities::UP:
		p.set_Y(place.get_Y() - 1);
		// for making the pacman walk at a normal speed even walking up/down where the distance between spaces is smaller then when walking right/left
		Sleep(30);
		if (p.get_Y() == 0)
			p.set_Y(Utilities::HEIGHT_OF_BOARD - 1);
		break;
	case Utilities::DOWN:
		p.set_Y(place.get_Y() + 1);
		Sleep(30);
		if (p.get_Y() == Utilities::HEIGHT_OF_BOARD - 1)
			p.set_Y(0);
		break;
	case Utilities::RIGHT:
		Sleep(10);
		p.set_X(place.get_X() + 1);
		if (p.get_X() == Utilities::WIDTH_OF_BOARD - 2)
			p.set_X(0);
		break;
	case Utilities::LEFT:
		Sleep(10);
		p.set_X(place.get_X() - 1);
		if (p.get_X() == 0)
			p.set_X(Utilities::WIDTH_OF_BOARD - 2);
		break;
	case Utilities::STAY:
		break;
	}

	return p;
}

void Pacman::init()
{
	lives = 3;
	points = 0;
	direction = Utilities::STAY;
	initPlace();	
}

void Pacman::initPlace()
{
	Point p(Utilities::START_X_PAC, Utilities::START_Y_PAC);
	place = p;
	Utilities::printCharToBoard(place, Utilities::PAC_SIGN);
}