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
    engine.scene->assets[0] = rect;
    rect->height = 10;
    rect->width = 10;
    rect->pos_x = 100;
    rect->pos_y = 100;
    rect->color = 0x03;

    engine.start();




    return 0;
}
