#include "interfaceBox.h"

INTERFACE_BOX::INTERFACE_BOX(RENDERER_2D* renderer) : RECTANGLE(renderer)
{

}

void INTERFACE_BOX::Draw()
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
			if ((i == pos_x + offset_x) && ((j == pos_y + offset_y) || (j == pos_y + width + offset_y - 1)))
			{
				continue;
			}
			if ((i == pos_x + height + offset_x - 1) && ((j == pos_y + offset_y) || (j == pos_y + width + offset_y - 1)))
			{
				continue;
			}
			if ((i - (pos_x + offset_x)) < 1 || (j - (pos_y + offset_y)) < 1 || (height - i + (pos_x + offset_x)) <= 1 || (width - j + (pos_y + offset_y)) <= 1)
			{
				renderer->writePixel(i, j, outlineColor);
				continue;
			}
			if ((i == pos_x + height + offset_x - 2) && ((j == pos_y + offset_y+1) || (j == pos_y + width + offset_y - 2)))
			{
				renderer->writePixel(i, j, jewelColor);
				continue;
			}
			if ((i == pos_x + offset_x + 1) && ((j == pos_y + offset_y + 1) || (j == pos_y + width + offset_y - 2)))
			{
				renderer->writePixel(i, j, jewelColor);
				continue;
			}
			if ((i < pos_x + offset_x + 3) && ((j < pos_y + offset_y + 3) || (j > pos_y + width + offset_y - 4)))
			{
				renderer->writePixel(i, j, outlineColor);
				continue;
			}
			if ((i > pos_x + height + offset_x - 4) && ((j < pos_y + offset_y + 3) || (j > pos_y + width + offset_y - 4)))
			{
				renderer->writePixel(i, j, outlineColor);
				continue;
			}
			/*if ((i = pos_x + height + offset_x - 5) && ((j == pos_y + offset_y + 2) || (j == pos_y + width + offset_y - 3)))
			{
				renderer->writePixel(i, j, outlineColor);
				continue;
			}
			if ((i < pos_x + offset_x + 3) && ((j == pos_y + offset_y + 2) || (j == pos_y + width + offset_y - 3)))
			{
				renderer->writePixel(i, j, outlineColor);
				continue;
			}*/

			renderer->writePixel(i, j, color);
		}
	}
	NODE_2D::Draw();
}