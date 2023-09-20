#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

void main(void)
{

	COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	for (size_t y = 0; y < 100; y++)
	{
		buffer[0][y].Char.UnicodeChar = 0x2580;
		buffer[0][y].Attributes = 0x0001 | 0x0002 | 0x0008;
	}

	WriteConsoleOutputW(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	getchar();
}