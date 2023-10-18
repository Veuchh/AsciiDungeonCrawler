#pragma once
#include "gameScript.h"
#include "sprite2D.h"
#include <string>

class ANIMATED_SPRITE : GAME_SCRIPT
{
private:
	SPRITE_2D* m_sprite;
public:
	virtual void Update();
	void PlayAnimation(std::string animationID);
};

