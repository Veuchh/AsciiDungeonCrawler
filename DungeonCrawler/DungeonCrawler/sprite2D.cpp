#include "sprite2D.h"

SPRITE_2D::SPRITE_2D(RENDERER_2D* renderer) : ASSET_2D(renderer) {}

void SPRITE_2D::Draw()
{
    for (size_t col = 0; col < spriteData->m_columns; col++)
    {
        for (size_t row = 0; row < spriteData->m_rows; row++)
        {
            if (spriteData->m_pixels[row][col] >= 0)
            {
                renderer->writePixel(pos_x + col, pos_y + row, spriteData->m_pixels[row][col]);
            }
        }
    }
	NODE_2D::Draw();
}