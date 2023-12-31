#include "enemy_data.h"
#include <stdlib.h>
#include "sprite2D.h"
#include "spriteParser.h"
#include "scene.h"

int ENEMY_DATA::GetRandomCooldownDuration()
{
	return  rand() % (m_maxCooldown - m_minCooldown + 1) + m_minCooldown;
}

int ENEMY_DATA::GetCurrentHP()
{
	return m_currentHP;
}

int ENEMY_DATA::GetCurrentPercentHP()
{
	return m_currentHP *100 / m_maxHP;
}

int ENEMY_DATA::GetAttackStartupDelay()
{
	return m_attackStartupDelay;
}

/// <param name="healthAmount">The amount of health to remove to the enemy. It has to be positive.</param>
/// <returns>True if the enemy hp is below zero after the hit, false otherwise</returns>
bool ENEMY_DATA::Hit(int healthAmount)
{
	m_currentHP = m_currentHP - healthAmount;
	return m_currentHP <= 0;
}

ENEMY_DATA::ENEMY_DATA(int minCooldown, int maxCooldown, int attackStartupDelay, int maxHP, std::string enemySprite, std::string enemyAttackSprite, std::string enemyHitSprite) :
	m_minCooldown(minCooldown), m_maxCooldown(maxCooldown), m_attackStartupDelay(attackStartupDelay), m_maxHP(maxHP)
{
	m_currentHP = maxHP;
	m_enemySpriteIdle = SPRITE_PARSER::ParseSprite(enemySprite);
	m_enemySpriteAttack = SPRITE_PARSER::ParseSprite(enemyAttackSprite);
	m_enemySpriteHit = SPRITE_PARSER::ParseSprite(enemyHitSprite);

	//TODO will need to use the system tha loads all sprites
	m_enemySprite = new SPRITE_2D(RENDERER_2D::Instance);
	m_enemySprite->spriteData = m_enemySpriteIdle;
	m_enemySprite->pos_x = 13;
	m_enemySprite->pos_y = 30;
	m_enemySprite->height = m_enemySprite->spriteData->m_columns;
	m_enemySprite->width = m_enemySprite->spriteData->m_rows;
	SCENE::Instance->addChildNode(m_enemySprite);
}

void ENEMY_DATA::ResetEnemy()
{
	m_currentHP = m_maxHP;
}
