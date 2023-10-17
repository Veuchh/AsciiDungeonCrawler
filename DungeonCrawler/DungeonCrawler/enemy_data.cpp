#include "enemy_data.h"
#include <stdlib.h>
#include "sprite2D.h"
#include "spriteParser.h"
#include "scene.h"

int ENEMY_DATA::GetRandomCooldownDuration()
{
    return  rand() % (m_maxCooldown - m_minCooldown + 1) + m_minCooldown;
}

/// <param name="healthAmount">The amount of health to remove to the enemy. It has to be positive.</param>
/// <returns>True if the enemy hp is below zero after the hit, false otherwise</returns>
bool ENEMY_DATA::Hit(int healthAmount)
{
    m_currentHP = m_currentHP - healthAmount;
    return m_currentHP <= 0;
}

ENEMY_DATA::ENEMY_DATA(int minCooldown, int maxCooldown, int maxHP, std::string enemySprite):
    m_minCooldown(minCooldown), m_maxCooldown(maxCooldown), m_maxHP(maxHP)
{
    m_currentHP = maxHP;

    //TODO will need to use the system tha loads all sprites
    //TODO Store the sprite in the data
    SPRITE_2D* sprite3 = new SPRITE_2D(RENDERER_2D::Instance);
    sprite3->spriteData = SPRITE_PARSER::ParseSprite("../bat_idle.bmp");
    sprite3->pos_x = sprite3->spriteData->m_rows / 2;
    sprite3->pos_y = sprite3->spriteData->m_columns / 2;
    sprite3->height = sprite3->spriteData->m_columns;
    sprite3->width = sprite3->spriteData->m_rows; 
    SCENE::Instance->addChildNode(sprite3);
    sprite3->SetPosition(SCREEN_CENTER);
}
