#include "rectangle.h"

void RECTANGLE::Draw()
{
	for (int i = pos_x; i < pos_x+height; ++i)
	{
		for (int j = pos_y; j < pos_y+width; ++j)
		{
			if (outline == true)
			{
				if (i-pos_x < outlineSize || j-pos_y < outlineSize || height - i + pos_x <= outlineSize || width - j + pos_y <= outlineSize)
				{
					renderer->writePixel(i, j, outlineColor);
					continue;
				}
			}
			renderer->writePixel(i, j, color);
		}
	}
	NODE_2D::Draw();
}



RECTANGLE::RECTANGLE(RENDERER_2D* renderer) : ASSET_2D(renderer){}