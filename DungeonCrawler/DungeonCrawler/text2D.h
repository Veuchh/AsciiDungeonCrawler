#include "asset2D.h"
#include <string>
#pragma once

class TEXT_2D : public ASSET_2D {
public:
	WORD color;
	virtual void Draw();
	std::string content;
	TEXT_2D(RENDERER_2D* renderer);
private:
	void WriteLine(short pos_x, short start_y, short maxLenght,std::string content, int lineStart);
};