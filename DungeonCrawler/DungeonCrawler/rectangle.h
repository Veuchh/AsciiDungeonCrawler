#include "asset2D.h"
#include <Windows.h>

#pragma once


class RECTANGLE:ASSET_2D {
public:
	WORD color;
	void Draw(WORD** px);
};