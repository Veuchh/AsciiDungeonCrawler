#pragma once
#include "gameScript.h"
#include "enemy_data.h"

#define ATTACK_COOLDOWN 20;
#define DEFEND_DURATION 5;
#define DEFEND_COOLDOWN 3;

class COMBAT : public GAME_SCRIPT
{
private:
	ENEMY_DATA* m_enemy;
	int m_remainingFramesBeforeEnemyAttack;
	int m_remainingAttackCooldown;
	int m_remainingDefendCooldown;
	bool m_isDefending = false;
	void HandleAttack(); 
	void HandleDefend();
	SPRITE_2D* m_swordSprite;
	SPRITE_2D* m_shieldSprite;
public:
	virtual void Update();
	COMBAT();
};