#include "node2D.h"
#pragma once

class ASSET_2D : public NODE_2D {
public:
	int pos_x;
	int pos_y;
	int width;
	int height;
	ASSET_2D(RENDERER_2D* renderer);
};