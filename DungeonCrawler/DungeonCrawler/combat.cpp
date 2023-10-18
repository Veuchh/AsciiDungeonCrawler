#include "combat.h"
#include <fstream>
#include "scene.h"
#include "spriteParser.h"
#include "player_data.h"

std::ofstream ofs;

void COMBAT::Update()
{
	m_swordSprite->Update();

	m_enemy->m_enemySprite->spriteData = SPRITE_PARSER::ParseSprite("../bat_idle.bmp");
	m_remainingFramesBeforeEnemyAttack--;

	HandleAttack();

	HandleDefend();

	if (!m_enemy->m_isEnemyAttacking && m_remainingFramesBeforeEnemyAttack <= 0)
	{
		m_enemy->m_isEnemyAttacking = true;

		m_remainingFramesBeforeEnemyAttack = m_enemy->GetAttackStartupDelay();
		ofs << "Start Enemy Attack Startup Delay" << std::endl;

		m_glyphSprite->isVisible = true;
	}

	else if (m_enemy->m_isEnemyAttacking && m_remainingFramesBeforeEnemyAttack <= 0)
	{
		ofs << "Enemy Attacks" << std::endl;
		m_enemy->m_enemySprite->spriteData = SPRITE_PARSER::ParseSprite("../bat_attack.bmp");

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

		m_enemy->m_isEnemyAttacking = false;
		m_remainingFramesBeforeEnemyAttack = m_enemy->GetRandomCooldownDuration();
		ofs << "Next attack in " << m_remainingFramesBeforeEnemyAttack << " frames" << std::endl;
		m_glyphSprite->isVisible = false;
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

		m_swordSprite->PlayAnimation();

		bool enemyDead = m_enemy->Hit(PLAYER_DATA::Instance->GetPlayerAttack());

		if (enemyDead)
		{
			//TODO enemy death anim
			//TODO : end battle
			ofs << "ENEMY DIED" << std::endl;
		}
		else
		{
			m_enemy->m_enemySprite->spriteData = SPRITE_PARSER::ParseSprite("../bat_hit.bmp");
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
			m_shieldSprite->spriteData = SPRITE_PARSER::ParseSprite("../shield_down.bmp");
			return;
		}

		if (m_remainingDefendCooldown <= 0)
		{
			ofs << "Cooldown over, can defend again" << std::endl;
		}

		return;
	}

	if (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		m_isDefending = true;
		m_remainingDefendCooldown = DEFEND_DURATION;
		ofs << "Defend input" << std::endl;
		m_shieldSprite->spriteData = SPRITE_PARSER::ParseSprite("../shield_up.bmp");
	}
}

COMBAT::COMBAT()
{
	ofs.open("enemyLogs.txt");

	m_roomSprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_roomSprite->spriteData = SPRITE_PARSER::ParseSprite("../background.bmp");
	m_roomSprite->pos_x = 0;
	m_roomSprite->pos_y = 0;
	m_roomSprite->height = m_roomSprite->spriteData->m_columns;
	m_roomSprite->width = m_roomSprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_roomSprite);

	m_glyphSprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_glyphSprite->spriteData = SPRITE_PARSER::ParseSprite("../glyph.bmp");
	m_glyphSprite->pos_x = 13;
	m_glyphSprite->pos_y = 30;
	m_glyphSprite->height = m_glyphSprite->spriteData->m_columns;
	m_glyphSprite->width = m_glyphSprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_glyphSprite);
	//m_glyphSprite->isVisible = false;

	m_enemy = new ENEMY_DATA(5, 10, 5, 100, "../bat_idle.bmp");
	m_remainingFramesBeforeEnemyAttack = m_enemy->GetRandomCooldownDuration();

	m_swordSprite = new ANIMATED_SPRITE("../Sword_idle.bmp", "../Sword_Slash_", 12);

	m_shieldSprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_shieldSprite->spriteData = SPRITE_PARSER::ParseSprite("../shield_down.bmp");
	m_shieldSprite->pos_x = 0;
	m_shieldSprite->pos_y = 0;
	m_shieldSprite->height = m_shieldSprite->spriteData->m_columns;
	m_shieldSprite->width = m_shieldSprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_shieldSprite);


	ofs << "Initiating combat. Next attack in " << m_remainingFramesBeforeEnemyAttack << " frames" << std::endl;
}
