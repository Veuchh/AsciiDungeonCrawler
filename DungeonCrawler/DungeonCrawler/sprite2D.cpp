#include "sprite2D.h"

SPRITE_2D::SPRITE_2D(RENDERER_2D* renderer) : ASSET_2D(renderer) {}

void SPRITE_2D::Draw()
{
    if (!isVisible)
    {
        return;
    }
    int offset_x = GetOffsetX();
    int offset_y = GetOffsetY();
    //pixels[rowIndex][columnIndex]
    for (size_t row = 0; row < spriteData->m_rows; row++)
    {
        for (size_t col = 0; col < spriteData->m_columns; col++)
        {
            if (spriteData->m_pixels[col][row] < 0x1000)
            {
                renderer->writePixel(pos_x + row + offset_x, pos_y + col + offset_y, spriteData->m_pixels[col][row]);
            }
        }
    }
	NODE_2D::Draw();
}