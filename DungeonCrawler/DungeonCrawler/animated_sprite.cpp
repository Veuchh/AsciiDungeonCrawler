#include "animated_sprite.h"
#include "scene.h"

void ANIMATED_SPRITE::Update()
{
	if (!m_isPlayingAnimation)
		return;

	m_sprite->spriteData = m_AnimationFrames[m_animationFrameIndex];
	m_animationFrameIndex++;

	//if we finished playing the animation
	if (m_animationFrameIndex == m_AnimationFrames.size())
	{
		m_sprite->spriteData = m_defaultSprite; 
		m_isPlayingAnimation = false;
	}
}

void ANIMATED_SPRITE::PlayAnimation()
{
	m_animationFrameIndex = 0;
	m_isPlayingAnimation = true;
}

ANIMATED_SPRITE::ANIMATED_SPRITE(std::string defaultSpriteName, std::string animationFilesName, int animationFramesAmount, int xPos, int yPos)
{
	m_defaultSprite = SPRITE_PARSER::ParseSprite(defaultSpriteName);

	for (size_t i = 0; i < animationFramesAmount; i++)
	{
		std::string s = animationFilesName + to_string(i) + ".bmp";
		m_AnimationFrames.push_back(SPRITE_PARSER::ParseSprite(s));
	}

	m_sprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_sprite->spriteData = m_defaultSprite;
	m_sprite->pos_x = xPos;
	m_sprite->pos_y = yPos;
	m_sprite->height = m_sprite->spriteData->m_columns;
	m_sprite->width = m_sprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_sprite);
}
