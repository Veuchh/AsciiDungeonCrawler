#pragma once
#include "node2d.h"
#include "healthBar.h"
#include "interfaceBox.h"
#include "sprite2D.h"
#include "spriteParser.h"
#include "text2D.h"


class USER_INTERFACE : public NODE_2D
{
public:
	USER_INTERFACE(RENDERER_2D* renderer);
	HEALTH_BAR* player_healthBar;
	HEALTH_BAR* enemy_healthBar;
	INTERFACE_BOX* messageBox;
	TEXT_2D* messageText;
	INTERFACE_BOX* shieldBox;
	INTERFACE_BOX* swordBox;
	SPRITE_2D* shieldSprite;
	SPRITE_2D* swordSprite;

	WORD cooldownColor = 0x2 | 0x4 | 0x8;
	WORD unavailableColor = 0x4 | 0x8;
	WORD readyColor = 0x2 | 0x8;
	virtual void Draw();
};