#pragma once
#include "animated_sprite.h"
#include "enemy_data.h"
#include "userInterface.h"

#define ATTACK_COOLDOWN 15;
#define DEFEND_DURATION 5;
#define DEFEND_COOLDOWN 3;

class COMBAT : public GAME_SCRIPT
{
private:
	ENEMY_DATA* m_enemy;
	int m_remainingFramesBeforeEnemyAttack;
	int m_remainingAttackCooldown = 0;
	int m_remainingDefendCooldown = 0;
	bool m_isDefending = false;
	void HandleAttack(); 
	void HandleDefend();

	USER_INTERFACE* ui;
	ANIMATED_SPRITE* m_swordSprite;
	SPRITE_2D* m_shieldSprite;
	SPRITE_2D* m_glyphSprite;
	SPRITE_2D* m_roomSprite;
public:
	virtual void Update();
	COMBAT();
};