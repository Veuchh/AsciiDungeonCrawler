#pragma once
#include "gameScript.h"
#include "sprite2D.h"
#include "SpriteParser.h"
#include <string>
#include <vector>

class ANIMATED_SPRITE : GAME_SCRIPT
{
private:
	SPRITE_DATA* m_defaultSprite;
	std::vector<SPRITE_DATA*> m_AnimationFrames;
	bool m_isPlayingAnimation = false;
	int m_animationFrameIndex = 0;
public:
	SPRITE_2D* m_sprite;
	virtual void Update();
	void PlayAnimation();
	ANIMATED_SPRITE(std::string defaultSpriteName, std::string animationFilesName, int animationFramesAmount, int xPos = 0, int yPos = 0);
};

