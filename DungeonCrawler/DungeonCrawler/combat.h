#pragma once
#include "gameScript.h"
#include "enemy_data.h"

class COMBAT : public GAME_SCRIPT
{
private:
	ENEMY_DATA* m_enemy;
	int m_remainingFramesBeforeEnemyAttack;
public:
	virtual void Update();
	COMBAT();
};