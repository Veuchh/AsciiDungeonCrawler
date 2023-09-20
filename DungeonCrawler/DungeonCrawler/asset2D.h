#include "windows.h"
#pragma once

class ASSET_2D {
public:
	int pos_x;
	int pos_y;
	int width;
	int height;
	virtual void Draw(CHAR_INFO** buffer)=0;
};