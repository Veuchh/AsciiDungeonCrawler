#pragma once
#include <Windows.h>

#define GAME_WIDTH 350
#define GAME_HEIGHT 120
#define PIXEL_WIDTH GAME_WIDTH
#define PIXEL_HEIGHT GAME_HEIGHT*2
#define FONT_SIZE_X 3
#define FONT_SIZE_Y 6
#define NB_LAYER 5





class RENDERER_2D {
private:
	HANDLE console_handle;
	CHAR_INFO buffer[GAME_HEIGHT][GAME_WIDTH];
	COORD bufferSize;
	COORD bufferCoord;
	SMALL_RECT gameSpace;
	int screen_width;
	int screen_height;
	int font_size_x;
	int font_size_y;

public:
	void start();
	void update();
	LONG_PTR setConsoleWindowStyle(INT n_index, LONG_PTR new_style);
	void writePixel(int coord_x, int coord_y, WORD color);

};