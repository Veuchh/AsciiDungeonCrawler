#pragma once
#include"node2D.h"
#include <string>

class ENEMY_DATA
{
public:
	int GetRandomCooldownDuration();
	bool Hit(int healthAmount);
	ENEMY_DATA(int minCooldown, int maxCooldown, int maxHP, std::string enemySprite);
private:
	int m_minCooldown;
	int m_maxCooldown;
	int m_maxHP;
	int m_currentHP;
	//SPRITE_2D* m_enemySprite;
};

