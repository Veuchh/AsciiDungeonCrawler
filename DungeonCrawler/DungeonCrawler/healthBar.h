#pragma once
#include "rectangle.h"

class HEALTH_BAR : public RECTANGLE
{
public:
	HEALTH_BAR(RENDERER_2D* renderer);
	WORD healthColor = 0x0004 | 0x0008;
	int value = 100; // At how much many % the bar is filled. From 0 to 100.
	virtual void Draw();
};