#define _WIN32_WINNT 0x0501
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "engine2D.h"
#include "rectangle.h"

int main()
{
    ENGINE_2D engine = ENGINE_2D();
    engine.start();
    engine.assets[0] = new ASSET_2D*[1];
    RECTANGLE* test_rect = new RECTANGLE();
    test_rect->color = 0x0F;
    test_rect->pos_x = 10;
    test_rect->pos_y = 10;
    test_rect->width = 10;
    test_rect->height = 10;
    engine.assets[0][0] =(ASSET_2D*) test_rect;

    while (true) {
        engine.update();

    }


    return 0;
}

//Si le new style est à 0, la fenetre n'a absolument rien à part son contenu
LONG_PTR setConsoleWindowStyle(INT n_index, LONG_PTR new_style)
{
    /*The function does not clear the last error information. if last value was zero.*/
    SetLastError(NO_ERROR);

    HWND hwnd_console = GetConsoleWindow();
    LONG_PTR style_ptr = SetWindowLongPtr(hwnd_console, n_index, new_style);
    SetWindowPos(hwnd_console, 0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_DRAWFRAME);

    //show window after updating
    ShowWindow(hwnd_console, SW_SHOW);

    return style_ptr;
}