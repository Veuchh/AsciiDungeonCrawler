#pragma once
class PLAYER_DATA
{
public:
	int GetPlayerAttack();
	int GetCurrentHP();
	int GetCurrentPercentHP();
	bool HitPlayer(int damage);
	PLAYER_DATA(int maxHP, int playerAttack);
	void ResetPlayer();
	static PLAYER_DATA* Instance;
private:
	int m_maxHP;
	int m_currentHP;
	int m_playerAttack;
};

