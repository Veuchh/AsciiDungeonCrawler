#pragma once
#include <Windows.h>

#define GAME_WIDTH 160
#define GAME_HEIGHT 46
#define PIXEL_WIDTH GAME_WIDTH
#define PIXEL_HEIGHT GAME_HEIGHT*2
#define FONT_SIZE_X 6
#define FONT_SIZE_Y 12
#define NB_LAYER 5
#define PIXEL_CHAR 0x2584





class RENDERER_2D {
private:
	HANDLE console_handle;
	CHAR_INFO buffer[GAME_HEIGHT][GAME_WIDTH];
	COORD bufferSize;
	COORD bufferCoord;
	SMALL_RECT gameSpace;

	short screen_width;
	short screen_height;
	short offset_x;
	short offset_y;
	short game_width;
	short game_height;

	short font_size_x;
	short font_size_y;

public:
	void start();
	void update();
	LONG_PTR setConsoleWindowStyle(INT n_index, LONG_PTR new_style);
	void writePixel(int coord_x, int coord_y, WORD color);
	void writeChar(int coord_x, int coord_y, CHAR value, WORD color);
	void fill(WORD color);
	static RENDERER_2D Instance;
};