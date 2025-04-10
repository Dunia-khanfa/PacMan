#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "TheGame.h"

int main()
{
	TheGame* game = new TheGame();
	game->showMenu();

	delete[]game;
}