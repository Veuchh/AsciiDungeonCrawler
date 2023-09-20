#include "asset2D.h"
#include <Windows.h>

#pragma once


class RECTANGLE:public ASSET_2D {
public:
	WORD color;
	void Draw(CHAR_INFO** px);
};