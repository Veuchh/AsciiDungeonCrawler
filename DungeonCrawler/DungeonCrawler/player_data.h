#pragma once
class PLAYER_DATA
{
public:
	int GetPlayerAttack();
	int GetCurrentHP();
	bool HitPlayer(int damage);
	PLAYER_DATA(int maxHP, int playerAttack);
	static PLAYER_DATA* Instance;
private:
	int m_maxHP;
	int m_currentHP;
	int m_playerAttack;
};

