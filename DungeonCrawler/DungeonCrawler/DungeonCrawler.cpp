#define _WIN32_WINNT 0x0501
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include "renderer2D.h"
#include "engine2D.h"
#include "scene.h"
#include "rectangle.h"
#include "spriteData.h"
#include "spriteParser.h"
#include "text2D.h"
#include "sprite2D.h"

int main()
{
    RENDERER_2D* renderer = new RENDERER_2D();
    SCENE* main_scene = new SCENE(renderer);
    main_scene->backgroundColor = 0xAA;
    ENGINE_2D engine = ENGINE_2D(renderer, main_scene);
    RECTANGLE* rect = new RECTANGLE(renderer);
    engine.scene->addChildNode(rect);
    rect->height = 10;
    rect->width = 10;
    rect->pos_x = 50;
    rect->pos_y = 50;
    rect->color = 0x03;
    RECTANGLE* rect2 = new RECTANGLE(renderer);
    engine.scene->addChildNode(rect2);
    rect2->height = 50;
    rect2->width = 10;
    rect2->pos_x = 30;
    rect2->pos_y = 30;
    rect2->color = 0x08;
    RECTANGLE* rect3 = new RECTANGLE(renderer);
    engine.scene->addChildNode(rect3);
    rect3->height = 20;
    rect3->width = 20;
    rect3->pos_x = 30;
    rect3->pos_y = 30;
    rect3->color = 0x0B;
    rect3->outline = true;
    rect3->outlineSize = 2;
    rect3->outlineColor = 0x00;
    TEXT_2D* text = new TEXT_2D(renderer);
    engine.scene->addChildNode(text);
    text->content = "TEST \nTEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST";
    text->color = 0x34;
    text->height = 30;
    text->width = 40;
    text->pos_x = 10;
    text->pos_y = 10;
    SPRITE_2D* sprite = new SPRITE_2D(renderer);
    sprite->pos_x = 60;
    sprite->pos_y = 60;
    sprite->spriteData = SPRITE_PARSER::ParseSprite("../testSprite.bmp");
    sprite->height = sprite->spriteData->m_columns;
    sprite->width = sprite->spriteData->m_rows;
    engine.scene->addChildNode(sprite);
    SPRITE_2D* sprite2 = new SPRITE_2D(renderer);
    sprite2->pos_x = 20;
    sprite2->pos_y = 100;
    sprite2->spriteData = SPRITE_PARSER::ParseSprite("../testSprite2.bmp");
    sprite2->height = sprite2->spriteData->m_columns;
    sprite2->width = sprite2->spriteData->m_rows;
    engine.scene->addChildNode(sprite2);




    engine.start();

    return 0;
}
