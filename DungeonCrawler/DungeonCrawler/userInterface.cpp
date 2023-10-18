#include "userInterface.h"

USER_INTERFACE::USER_INTERFACE(RENDERER_2D* renderer) : NODE_2D(renderer){
	player_healthBar = new HEALTH_BAR(RENDERER_2D::Instance);
	player_healthBar->width = PIXEL_WIDTH;
	player_healthBar->height = 8;
	player_healthBar->outline = true;
	player_healthBar->outlineSize = 1;
	player_healthBar->outlineColor = 0x8;
	player_healthBar->color = 0;

	enemy_healthBar = new HEALTH_BAR(RENDERER_2D::Instance);
	enemy_healthBar->width = 102;
	enemy_healthBar->height = 6;
	enemy_healthBar->outline = true;
	enemy_healthBar->outlineSize = 1;
	enemy_healthBar->outlineColor = 0x8;
	enemy_healthBar->color = 0;

	messageBox = new INTERFACE_BOX(RENDERER_2D::Instance);
	messageBox->outlineColor = 0x03;
	messageBox->width = 36;
	messageBox->height = 20;
	messageText = new TEXT_2D(RENDERER_2D::Instance);
	messageText->content = "COMMANDS:\nPRESS A TO ATTACK\nPRESS D TO DEFEND\nPRESS SPACE TO START THE GAME";
	messageText->color = 0xF;
	messageText->width = 25;
	messageText->height = 10;
	messageBox->addChildNode(messageText);

	shieldBox = new INTERFACE_BOX(RENDERER_2D::Instance);
	shieldBox->anchor = ANCHOR_CENTERED;
	shieldBox->outlineColor = 0x8;
	shieldBox->pos_x = PIXEL_HEIGHT - 20;
	shieldBox->pos_y = PIXEL_WIDTH*2 / 10;
	shieldBox->width = 18;
	shieldBox->height = 18;
	shieldBox->color = readyColor;

	shieldSprite = new SPRITE_2D(renderer);
	shieldSprite->spriteData = SPRITE_PARSER::ParseSprite("../icon_shield.bmp");
	shieldSprite->height = shieldSprite->spriteData->m_rows;
	shieldSprite->width = shieldSprite->spriteData->m_columns;
	shieldSprite->anchor = ANCHOR_CENTERED;
	shieldSprite->pos_x = PIXEL_HEIGHT - 20;
	shieldSprite->pos_y = PIXEL_WIDTH * 2 / 10;
	shieldBox->addChildNode(shieldSprite);


	swordBox = new INTERFACE_BOX(RENDERER_2D::Instance);
	swordBox->anchor = ANCHOR_CENTERED;
	swordBox->outlineColor = 0x8;
	swordBox->pos_x = PIXEL_HEIGHT-20;
	swordBox->pos_y = PIXEL_WIDTH - PIXEL_WIDTH*2/10;
	swordBox->width = 18;
	swordBox->height = 18;
	swordBox->color = readyColor;

	swordSprite = new SPRITE_2D(renderer);
	swordSprite->spriteData = SPRITE_PARSER::ParseSprite("../icon_sword.bmp");
	swordSprite->height = swordSprite->spriteData->m_rows;
	swordSprite->width = swordSprite->spriteData->m_columns;
	swordSprite->anchor = ANCHOR_CENTERED;
	swordSprite->pos_x = PIXEL_HEIGHT - 20;
	swordSprite->pos_y = PIXEL_WIDTH - PIXEL_WIDTH * 2 / 10;
	swordBox->addChildNode(swordSprite);

	enemy_healthBar->SetPosition(SCREEN_TOP);
	enemy_healthBar->pos_x = enemy_healthBar->pos_x + 4;
	player_healthBar->SetPosition(SCREEN_BOTTOM);
	messageBox->SetPosition(SCREEN_CENTER);
	messageText->SetPosition(SCREEN_CENTER);
	//messageBox->pos_x = bottomBox->pos_x - 10;
}

void USER_INTERFACE::Draw()
{
	if (!isVisible)
	{
		return;
	}
	enemy_healthBar->Draw();
	player_healthBar->Draw();
	shieldBox->Draw();
	swordBox->Draw();
	messageBox->Draw();
	NODE_2D::Draw();
}