#include "combat.h"
#include <fstream>
#include "scene.h"
#include "spriteParser.h"
#include "player_data.h"

std::ofstream ofs;

void COMBAT::Update()
{
	m_remainingFramesBeforeEnemyAttack--;

	HandleAttack();

	HandleDefend();

	if (m_remainingFramesBeforeEnemyAttack <= 0)
	{
		ofs << "Enemy Attacks" << std::endl;

		if (!m_isDefending)
		{
			bool isPlayerDead = PLAYER_DATA::Instance->HitPlayer(10);

			if (isPlayerDead)
			{
				ofs << "PLAYER DIED ! GAME OVER" << std::endl;
				//TODO Kill player game over
			}

			else
			{
				ofs << "PLAYER HIT ! REMAINING HP : " << PLAYER_DATA::Instance->GetCurrentHP() << std::endl;
			}
		}
		else
		{
			ofs << "Player defended the attack !" << std::endl;
		}

		//TODO : attack animation
		m_remainingFramesBeforeEnemyAttack = m_enemy->GetRandomCooldownDuration();
		ofs << "Next attack in " << m_remainingFramesBeforeEnemyAttack << " frames" << std::endl;
	}
}

void COMBAT::HandleAttack()
{
	if (m_remainingAttackCooldown > 0)
	{
		m_remainingAttackCooldown--;

		return;
	}

	if (GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		ofs << "Attack input" << std::endl;

		m_remainingAttackCooldown = ATTACK_COOLDOWN;

		//TODO Add sword animation

		bool enemyDead = m_enemy->Hit(PLAYER_DATA::Instance->GetPlayerAttack());

		if (enemyDead)
		{
			//TODO enemy death anim
			//TODO : end battle
			ofs << "ENEMY DIED" << std::endl;
		}
		else
		{
			//TODO : enemy hit anim
			ofs << "ENEMY HIT. REMAINING HP : " << m_enemy->GetCurrentHP() << std::endl;
		}
	}
}

void  COMBAT::HandleDefend()
{
	if (m_remainingDefendCooldown > 0)
	{
		m_remainingDefendCooldown--;
		if (m_isDefending && m_remainingDefendCooldown <= 0)
		{
			m_isDefending = false;
			m_remainingDefendCooldown = DEFEND_COOLDOWN;
			ofs << "Defend over, starting cooldown" << std::endl;
		}

		return;
	}

	if (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		m_isDefending = true;
		m_remainingDefendCooldown = DEFEND_DURATION;
		ofs << "Defend input" << std::endl;
	}
}

COMBAT::COMBAT()
{
	ofs.open("enemyLogs.txt");
	m_enemy = new ENEMY_DATA(5, 10, 100, "../bat_idle.bmp");

	m_remainingFramesBeforeEnemyAttack = m_enemy->GetRandomCooldownDuration();
	ofs << "Initiating combat. Next attack in " << m_remainingFramesBeforeEnemyAttack << " frames" << std::endl;

	m_swordSprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_swordSprite->spriteData = SPRITE_PARSER::ParseSprite("../sword_idle.bmp");
	m_swordSprite->pos_x = 0;
	m_swordSprite->pos_y = 0;
	m_swordSprite->height = m_swordSprite->spriteData->m_columns;
	m_swordSprite->width = m_swordSprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_swordSprite);

	m_shieldSprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_shieldSprite->spriteData = SPRITE_PARSER::ParseSprite("../shield_down.bmp");
	m_shieldSprite->pos_x = 0;
	m_shieldSprite->pos_y = 0;
	m_shieldSprite->height = m_shieldSprite->spriteData->m_columns;
	m_shieldSprite->width = m_shieldSprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_shieldSprite);
}
