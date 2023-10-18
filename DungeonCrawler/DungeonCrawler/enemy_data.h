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
	ENEMY_DATA(int minCooldown, int maxCooldown, int attackStartupDelay, int maxHP, std::string enemySprite, std::string enemyAttackSprite, std::string enemyHitSprite);
	SPRITE_2D* m_enemySprite;
	SPRITE_DATA* m_enemySpriteIdle;
	SPRITE_DATA* m_enemySpriteAttack;
	SPRITE_DATA* m_enemySpriteHit;
	void ResetEnemy();
private:
	int m_minCooldown;
	int m_maxCooldown;
	int m_maxHP;
	int m_currentHP;
	int m_attackStartupDelay;
};

