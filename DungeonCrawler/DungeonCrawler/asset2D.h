#include "windows.h"
#include "renderer2D.h"
#pragma once

class ASSET_2D {
public:
	RENDERER_2D* renderer;
	int pos_x;
	int pos_y;
	int width;
	int height;
	virtual void Draw() = 0;
	ASSET_2D(RENDERER_2D* renderer);
};