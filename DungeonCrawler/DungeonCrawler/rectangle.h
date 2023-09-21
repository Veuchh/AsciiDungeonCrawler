#pragma once
#include "asset2D.h"
#include <Windows.h>



class RECTANGLE:public ASSET_2D {
public:
	WORD color;
	virtual void Draw();
	RECTANGLE(RENDERER_2D* renderer);
};