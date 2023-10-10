#include "text2D.h"

TEXT_2D::TEXT_2D(RENDERER_2D* renderer) : ASSET_2D(renderer) {}

void TEXT_2D::Draw()
{
	NODE_2D::Draw();

	short line = pos_x/2;
	int current = 0;
	for (int i = 0; i < height / 2;i++)
	{
		current += WriteLine(line+i, pos_y, width, content, current);
		//current += width;
		if (current > content.length())
		{
			return;
		}
	}
}

int TEXT_2D::WriteLine(short pos_x,short start_y, short maxLenght, std::string content, int lineStart)
{
	if (pos_x < GAME_HEIGHT && start_y<GAME_WIDTH)
	{
		int i = 0;
		for (i = 0; i < maxLenght && lineStart+i <= content.length()-1; ++i)
		{
			if (content[lineStart+i] == '\n')
				return ++i;
			renderer->writeChar(pos_x, start_y + i, content[lineStart+i], color);
		}
		return i;
	}
	return maxLenght;
}