#include "rectangle.h"

void RECTANGLE::Draw()
{
	NODE_2D::Draw();
	for (int i = pos_x; i < pos_x+height; ++i)
	{
		for (int j = pos_y; j < pos_y+width; ++j)
		{
			renderer->writePixel(i, j, color);
		}
	}
}

RECTANGLE::RECTANGLE(RENDERER_2D* renderer) : ASSET_2D(renderer)
{
}