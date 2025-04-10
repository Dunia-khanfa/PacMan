#include "Utilities.h"

void Utilities::hideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 100;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Utilities::printCharToBoard(const Point& p, char ch)
{
	cout << "\033[" << p.get_Y() + 1 << ";" << p.get_X() + 1 << "H";
	cout << ch;
}

void Utilities::updateInfoLine(const int x_whatToUpdate, int data)
{
	cout << "\033[" << HEIGHT_OF_BOARD + 1 << ";" << x_whatToUpdate << "H";
	cout << data;
}

void Utilities::waitForESC()
{
	while (_getch() != ASCII_OF_ESC)
	{
		// wait
	}
}

void Utilities::clearInputBuffer()
{
	while (std::cin.peek() != '\n' && std::cin.peek() != EOF)
	{
		std::cin.ignore(1);
	}
}