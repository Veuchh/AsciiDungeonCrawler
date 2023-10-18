#pragma once
#include"sprite2D.h"
#include <string>

class ENEMY_DATA
{
public:
	int GetRandomCooldownDuration();
	int GetCurrentHP();
	int GetCurrentPercentHP();
	int GetAttackStartupDelay();
	bool Hit(int healthAmount);
	bool m_isEnemyAttacking = false;
	ENEMY_DATA(int minCooldown, int maxCooldown, int attackStartupDelay, int maxHP, std::string enemySprite);
	SPRITE_2D* m_enemySprite;
private:
	int m_minCooldown;
	int m_maxCooldown;
	int m_maxHP;
	int m_currentHP;
	int m_attackStartupDelay;
};

