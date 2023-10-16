#pragma once
#include "gameScript.h"
#include "rectangle.h"

class MOVING_BOX_SCRIPT : public GAME_SCRIPT 
{
public:
	RECTANGLE* rectangle;
	int speed_x = 0;
	int speed_y = 0;
	void Bind(RECTANGLE* rect);
	virtual void Update();
};