#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <dos.h>

#include "Pacman.h"
#include "Board.h"

class Ghost;

#define NOG 2

class TheGame
{
	Pacman pacman;
	Ghost* ghosts[NOG];
	Board original_board;
	Board board;
	int breadcrums;

public:
	TheGame();

	// this function is responsible for the progress of the game
	void start();

	int getBreadcrums() const { return breadcrums; }

	// the game is paused, waits for ESC and then continue the game
	void pauseGame();

	// sets the pacman and ghosts to their starting place (update the board and screen accordingly)
	void startAfterDeath();

	// starts a different game with the original board and 3 lives for the pacman
	void startAnotherTime();

	// moves the pacman based on input from user, and update the board and screen accordingly
	bool movePacman();

	// moves the ghosts randomly, and update the board and screen accordingly
	void moveGhosts(int time);

	// prints instructions to the screen, waits for ESC to return to the menu
	void instructions();

	// exit the program
	void exitGame() const;

	// shows the menu and the options for a new game, instructions, exit
	void showMenu();

	// returns if the pacman won the game (if there are no more breadcrums left)
	bool isWinner() const;

	// returns if the pacman lost the game (if he lost all his lives)
	bool isLooser() const;

	// updates breadcrums to their initialize amount (in the original board)
	void initGame();

	~TheGame();
};

