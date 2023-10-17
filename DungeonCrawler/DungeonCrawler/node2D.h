#include "windows.h"
#include "renderer2D.h"
#include <list>
#pragma once

class NODE_2D {
public:
	RENDERER_2D* renderer;
	NODE_2D* parent = 0;
	std::list<NODE_2D*> childs;
	bool isVisible = true;
	NODE_2D(RENDERER_2D* renderer);

	virtual void Draw();
	void addChildNode(NODE_2D* child);

};
