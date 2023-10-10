#include "spriteData.h"

SPRITE_DATA::SPRITE_DATA(WORD** pixels, int columns, int rows):m_pixels(pixels), m_columns(columns), m_rows(rows)
{
}

/*
* 
HOW TO ITERATE ON SPRITE_DATA->m_pixels

for (size_t col = 0; col < spriteData->m_columns; col++)
    {
        for (size_t row = 0; row < spriteData->m_rows; row++)
        {
            spriteData->m_pixels[row][col];
        }
    }

*/