#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Point.h"
#include "Utilities.h"

class Board
{
	char board[(Utilities::WIDTH_OF_BOARD * Utilities::HEIGHT_OF_BOARD) + 1];

	// prints the info line to the last line of the board (lives and score of pacman)
	void printInfoLine(int lives, int score) const;

public:
	Board();

	// prints the board to the screen
	void print(int lives, int score) const;

	const char* getBoard() const;

	// gets the char that is in (x,y)
	char get(int x, int y) const;

	// gets the char that is in p
	char getPoint(const Point& p) const;

	// sets the char that is in (x,y) to ch
	void set(int x, int y, char ch);

	// sets the char that is in p to ch
	void set(const Point& p, char ch);
};