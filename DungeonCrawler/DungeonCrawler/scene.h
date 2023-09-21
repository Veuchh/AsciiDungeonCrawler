#pragma once
#include "asset2D.h"
#include "renderer2D.h"


class SCENE {
public:
	SCENE(RENDERER_2D* renderer);
	RENDERER_2D* renderer;
	ASSET_2D** assets;
	void display();
	void addAsset(int layer, int pose_x, int pos_y, ASSET_2D asset);

};