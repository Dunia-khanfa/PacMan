#pragma once
#include "Ghost.h"
#include "Board.h"
#include "Utilities.h"

#include <conio.h>
#include <cctype>
#include <iostream>
#include <windows.h> // for Sleep()
using std::cout;
using std::cin;
using std::endl;

class Pacman
{
	int lives;
	int points;
	char direction;
	Point place;

public:
	Pacman() : lives(3), points(0), direction(Utilities::STAY), place(Utilities::START_X_PAC, Utilities::START_Y_PAC) { }

	Pacman(const Pacman&) = delete;

	int getPoints() const { return points; }

	int getLives() const { return lives; }

	Point getPlace() const { return place; }

	void setPoints(int _points) { if (_points >=0) points = _points; }

	void setLives(int _lives) { if(_lives >=0 && _lives <=3) lives = _lives; }

	void setDirection(char _direction) { if (_direction == Utilities::UP || _direction == Utilities::DOWN || _direction == Utilities::RIGHT || _direction == Utilities::LEFT || _direction == Utilities::STAY) direction = _direction; };

	// set the place of the pacman to p and checks and print to the screen the updated place
	// also, checks if in the new place the pacman eats a dot or gets eaten by a ghost and deals with that accordingly
	void setPlace(const Board& b, bool& wasDot, bool& wasGhost, const Point& p);

	// sees if the user pressed any key, if so:
	// if it's one of the directions, checks if the pacman can go there, if not, stay at the same place
	// if it's the ESC button, the function returns true, to notify the game needs to be paused (else, the function returns false)
	bool move(const Board& b, bool& wasDot, bool& wasGhost);

    // returns true if there is not a wall and the pacman can move, false otherwise
	bool canMove(const Point& p, const Board& b) const;

	// pacman "eats" a dot, so he gains a point
	void eatADot() { points++; }

	// pacman gets "eaten" by a ghost, so he loses a life
	void getEaten() { lives--; }

	// returns the point to which the pacman moves to based on his direction
	Point next();

	// initialize the pacman's lives to 3, points to 0 , direction to STAY and place to the starting point for the pacman
	void init();

	// initialize the pacman's place to the starting point for the pacman
	void initPlace();
};

