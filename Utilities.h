#pragma once
#include "Point.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <conio.h>

class Point;

using std::cout;
using std::endl;

class Utilities
{
public:
	enum { UP = 'W', DOWN = 'X', RIGHT = 'D', LEFT = 'A', STAY = 'S' };

	static const int HEIGHT_OF_BOARD = 24;
	static const int WIDTH_OF_BOARD = 81;
	static const int ASCII_OF_ESC = 27;
	static const char PAC_SIGN = '@';
	static const char GHOST_SIGN = '$';
	static const char DOT_SIGN = '.';
	static const char WALL_SIGN = '#';
	static const char SPACE_SIGN = ' ';
	static const int START_X_PAC = 40;
	static const int START_Y_PAC = 17;
	static const int X_OF_LIVES_IN_INFO_LINE = 8;
	static const int X_OF_SCORE_IN_INFO_LINE = 18;

	// hides the cursor
	static void hideCursor();

	// prints the ch to p on the screen
	static void printCharToBoard(const Point& p, char ch);

	// updates and prints the certian element that needs to be updated based on (x_whatToUpdate- this is the x of said elemnt in info line)
	static void updateInfoLine(const int x_whatToUpdate, int data);

	// wait in this function until the user press the ESC button
	static void waitForESC();

	static void clearInputBuffer();
};
