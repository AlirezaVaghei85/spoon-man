#pragma once
#include <windows.h>
using namespace std;

class Console
{
public:
	Console()
	{
		fill();
	}
	void fill()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		maxX = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		maxY = csbi.srWindow.Bottom - csbi.srWindow.Top /*+ 1*/;
	}
	int getMaxX() const
	{
		return maxX;
	}
	int getMaxY() const
	{
		return maxY;
	}
	void gotoxy(short a, short b) // Custom gotoxy() function
	{
		COORD cd; // Data type of co-ordinates
		cd.X = a; // Assign value to X- Co-ordinate
		cd.Y = b; // Assign value to Y Co-ordinate

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), cd);
	}
	void setFullScreen()
	{
		/*HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hOut, &csbi);
		SMALL_RECT windowRect = { 0, 0, csbi.dwSize.X - 1, csbi.dwSize.Y - 1 };
		SetConsoleWindowInfo(hOut, TRUE, &windowRect);*/

		/*HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD newSize = { 0, 0 };
		SetConsoleDisplayMode(hOut, CONSOLE_FULLSCREEN_MODE, &newSize);*/

		// HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		// CONSOLE_SCREEN_BUFFER_INFOEX csbi;
		// csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		// GetConsoleScreenBufferInfoEx(hOut, &csbi);

		// COORD coord = { 0, 0 }; // Set the coordinates to (0, 0)
		// if (!SetConsoleDisplayMode(hOut, CONSOLE_FULLSCREEN_MODE, &coord)) {
		//	std::cerr << "Error: SetConsoleDisplayMode failed." << std::endl;
		// }

		HWND console = GetConsoleWindow();
		RECT rect;
		GetWindowRect(console, &rect);

		// Move console window to top left corner of screen
		MoveWindow(console, 0, 0, GetSystemMetrics(SM_CXSCREEN) + 10, GetSystemMetrics(SM_CYSCREEN) - 30, TRUE);
	}
	COORD getCursorPosition()
	{
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO cbsi;
		if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
		{
			return cbsi.dwCursorPosition;
		}
		else
		{
			// The function failed. Call GetLastError() for details.
			COORD invalid = {0, 0};
			return invalid;
		}
	}
	void changeColor(int colorCode)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
	}

private:
	int maxX, maxY;
};