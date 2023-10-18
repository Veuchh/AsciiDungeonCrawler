#include "healthBar.h"

HEALTH_BAR::HEALTH_BAR(RENDERER_2D* renderer) : RECTANGLE(renderer){}

void HEALTH_BAR::Draw()
{
	if (!isVisible)
	{
		return;
	}
	int offset_x = GetOffsetX();
	int offset_y = GetOffsetY();
	for (int i = pos_x + offset_x; i < pos_x + height + offset_x; ++i)
	{
		for (int j = pos_y + offset_y; j < pos_y + width + offset_y; ++j)
		{
			if (outline == true)
			{
				if ((i - (pos_x + offset_x)) < outlineSize || (j - (pos_y + offset_y)) < outlineSize || (height - i + (pos_x + offset_x)) <= outlineSize || (width - j + (pos_y + offset_y)) <= outlineSize)
				{
					renderer->writePixel(i, j, outlineColor);
					continue;
				}
			}
			if (j - pos_y - offset_y < value*(width-outlineSize)/100)
			{
				renderer->writePixel(i, j, healthColor);
				continue;
			}
			renderer->writePixel(i, j, color);
		}
	}
	NODE_2D::Draw();
}