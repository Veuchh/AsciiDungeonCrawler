#include "text2D.h"

TEXT_2D::TEXT_2D(RENDERER_2D* renderer) : ASSET_2D(renderer) {}

void TEXT_2D::Draw()
{
	NODE_2D::Draw();

	short line = pos_x/2;
	int current = 0;
	for (int i = 0; i < height / 2;i++)
	{
		WriteLine(line+1, pos_y, width, content, current);
		current += width;
		if (current > content.length())
		{
			current = content.length();
		}
	}
}

void TEXT_2D::WriteLine(short pos_x,short start_y, short maxLenght, std::string content, int lineStart)
{
	if (pos_x < GAME_HEIGHT && start_y+maxLenght<GAME_WIDTH)
	{
		for (int i = 0; i < maxLenght && lineStart+i <= content.length(); ++i)
		{
			renderer->writeChar(pos_x, start_y + i, content[lineStart+i], color);
		}
	}
}