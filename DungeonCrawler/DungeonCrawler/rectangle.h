#pragma once
#include "asset2D.h"
#include <Windows.h>



class RECTANGLE:public ASSET_2D {
public:
	WORD color = 0x00;
	WORD outlineColor = 0x00;
	boolean outline = false;
	short outlineSize;
	virtual void Draw();
	RECTANGLE(RENDERER_2D* renderer);
};