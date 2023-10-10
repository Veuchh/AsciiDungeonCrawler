#define _WIN32_WINNT 0x0501
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "renderer2D.h"
#include "engine2D.h"
#include "scene.h"
#include "rectangle.h"

int main()
{
    RENDERER_2D renderer = RENDERER_2D();
    SCENE main_scene = SCENE(&renderer);
    ENGINE_2D engine = ENGINE_2D(&renderer, &main_scene);
    RECTANGLE* rect = new RECTANGLE(&renderer);
    engine.scene->addChildNode(rect);
    rect->height = 10;
    rect->width = 10;
    rect->pos_x = 50;
    rect->pos_y = 50;
    rect->color = 0x03;
    RECTANGLE* rect2 = new RECTANGLE(&renderer);
    engine.scene->addChildNode(rect2);
    rect2->height = 50;
    rect2->width = 10;
    rect2->pos_x = 30;
    rect2->pos_y = 30;
    rect2->color = 0x08;
    RECTANGLE* rect3 = new RECTANGLE(&renderer);
    engine.scene->addChildNode(rect3);
    rect3->height = 10;
    rect3->width = 10;
    rect3->pos_x = 10;
    rect3->pos_y = 10;
    rect3->color = 0x0A;

    engine.start();




    return 0;
}
