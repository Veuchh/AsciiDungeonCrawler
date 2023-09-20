#include "rectangle.h"

void RECTANGLE::Draw(WORD** px)
{
	for (int i = pos_x; i < height; ++i)
	{
		for (int j = pos_y; i < width; ++j)
		{
			px[i][j] = color;
		}
	}
}