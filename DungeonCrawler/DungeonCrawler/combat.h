#pragma once
#include "gameScript.h"
#include "enemy_data.h"
#include "userInterface.h"

#define ATTACK_COOLDOWN 20;
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
	SPRITE_2D* m_swordSprite;
	SPRITE_2D* m_shieldSprite;
	SPRITE_2D* m_glyphSprite;
public:
	virtual void Update();
	COMBAT();
};