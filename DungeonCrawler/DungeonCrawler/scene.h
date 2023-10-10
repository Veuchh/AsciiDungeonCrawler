#pragma once
#include "node2D.h"
#include "renderer2D.h"


class SCENE : public NODE_2D {
public:
	SCENE(RENDERER_2D* renderer);
	RENDERER_2D* renderer;
	void display();
	void addNode(int layer, int pose_x, int pos_y, NODE_2D asset);

};