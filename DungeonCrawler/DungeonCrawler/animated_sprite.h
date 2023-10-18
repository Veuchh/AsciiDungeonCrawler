#pragma once
#include "gameScript.h"
#include "sprite2D.h"
#include "SpriteParser.h"
#include <string>
#include <vector>

class ANIMATED_SPRITE : GAME_SCRIPT
{
private:
	std::vector<SPRITE_DATA*> m_AnimationFrames;
	int m_animationFrameIndex = 0;
public:
	SPRITE_DATA* m_defaultSprite;
	bool m_isPlayingAnimation = false;
	SPRITE_2D* m_sprite;
	virtual void Update();
	void PlayAnimation();
	ANIMATED_SPRITE(std::string defaultSpriteName, std::string animationFilesName, int animationFramesAmount, int xPos = 0, int yPos = 0);
};

