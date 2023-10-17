#include "node2D.h"

NODE_2D::NODE_2D(RENDERER_2D* renderer)
{
	this->renderer = renderer;
}

void NODE_2D::Draw()
{
	if (!isVisible)
	{
		return;
	}
	for (NODE_2D* child : childs)
	{
		child->Draw();
	}
}

void NODE_2D::addChildNode(NODE_2D* child)
{
	childs.push_back(child);
	child->parent = this;
}
