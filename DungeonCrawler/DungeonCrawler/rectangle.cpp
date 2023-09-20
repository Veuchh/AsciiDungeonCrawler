#include "rectangle.h"

void RECTANGLE::Draw(CHAR_INFO** buffer)
{
	for (int i = pos_x; i < pos_x+height; ++i)
	{
		for (int j = pos_y; j < pos_y+width; ++j)
		{
			if (i/2 !=1)
			{
				buffer[i][j].Attributes = buffer[i][j].Attributes & 0x0F;
				buffer[i][j].Attributes = buffer[i][j].Attributes | (color<<8);
			}
			else
			{
				buffer[i][j].Attributes = buffer[i][j].Attributes & 0xF0;
				buffer[i][j].Attributes = buffer[i][j].Attributes | color;
			}
		}
	}
}