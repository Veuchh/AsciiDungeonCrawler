#pragma once

#include <windows.h>
class SPRITE_DATA
{
public:
	WORD** m_pixels;
	int m_columns;
	int m_rows;

	SPRITE_DATA(WORD** pixels, int columns, int rows);
};

