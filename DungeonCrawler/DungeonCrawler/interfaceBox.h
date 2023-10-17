#pragma once
#include "rectangle.h"
#include "spriteData.h"

class INTERFACE_BOX : public RECTANGLE 
{
public:
	INTERFACE_BOX(RENDERER_2D* renderer);
	virtual void Draw();
};