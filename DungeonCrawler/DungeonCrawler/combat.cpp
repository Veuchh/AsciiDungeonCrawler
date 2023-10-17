#include "combat.h"
#include <fstream>

std::ofstream ofs;
void COMBAT::Update()
{
	m_remainingFramesBeforeEnemyAttack--;

	ofs << "Next attack in " << m_remainingFramesBeforeEnemyAttack << " frames" << std::endl;
	if (m_remainingFramesBeforeEnemyAttack <= 0)
	{
		m_remainingFramesBeforeEnemyAttack = m_enemy->GetRandomCooldownDuration();
		ofs << "Enemy Attacks" << std::endl;
	}
}

COMBAT::COMBAT()
{
	ofs.open("enemyLogs.txt");
	m_enemy = new ENEMY_DATA(50, 100, 100, "../bat_idle.bmp");

	m_remainingFramesBeforeEnemyAttack = m_enemy->GetRandomCooldownDuration();
	ofs << "Initiating combat. Next attack in " << m_remainingFramesBeforeEnemyAttack << " frames" << std::endl;
}
