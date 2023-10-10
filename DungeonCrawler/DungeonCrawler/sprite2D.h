#pragma once
#include "asset2D.h"
#include "spriteData.h"
#include "renderer2D.h"

class SPRITE_2D : public ASSET_2D
{
public:
	SPRITE_DATA* spriteData;
	virtual void Draw();
	SPRITE_2D(RENDERER_2D* renderer);
};