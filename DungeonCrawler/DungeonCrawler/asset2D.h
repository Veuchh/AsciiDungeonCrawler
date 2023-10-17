#include "node2D.h"
#pragma once

enum ANCHOR_TYPE {
	ANCHOR_TOP_LEFT,
	ANCHOR_CENTERED,
	ANCHOR_TOP,
	ANCHOR_BOTTOM,
	ANCHOR_RIGHT,
	ANCHOR_LEFT
};

enum SCREEN_POSITION {
	SCREEN_CENTER,
	SCREEN_RIGHT,
	SCREEN_LEFT,
	SCREEN_TOP,
	SCREEN_BOTTOM
};


class ASSET_2D : public NODE_2D {
public:
	ANCHOR_TYPE anchor = ANCHOR_TOP_LEFT;
	int pos_x = 0;
	int pos_y = 0;
	int width = 0;
	int height = 0;
	int GetOffsetX();
	int GetOffsetY();
	void SetPosition(SCREEN_POSITION pos);

	ASSET_2D(RENDERER_2D* renderer);
};