#include "player_data.h"

PLAYER_DATA* PLAYER_DATA::Instance;

int PLAYER_DATA::GetPlayerAttack()
{
	return m_playerAttack;
}

int PLAYER_DATA::GetCurrentHP()
{
	return m_currentHP;
}

int PLAYER_DATA::GetCurrentPercentHP()
{
	return m_currentHP*100 / m_maxHP;
}


bool PLAYER_DATA::HitPlayer(int damage)
{
	m_currentHP = m_currentHP - damage;
	return m_currentHP <= 0;
}

PLAYER_DATA::PLAYER_DATA(int maxHP, int playerAttack):
	m_maxHP(maxHP), m_playerAttack(playerAttack)
{
	Instance = this;
	m_currentHP = m_maxHP;
}

void PLAYER_DATA::ResetPlayer()
{
	m_currentHP = m_maxHP;
}
