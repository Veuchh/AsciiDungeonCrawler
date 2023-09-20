#include "engine2D.h"


void ENGINE_2D::start()
{
    int SCREEN_WIDTH = 0, SCREEN_HEIGHT = 0;
    LONG_PTR new_style = WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL;
    LONG_PTR setConsoleWindowStyle(INT, LONG_PTR);

    console_handle = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = FONT_SIZE_X;                   // Width of each character in the font
    cfi.dwFontSize.Y = FONT_SIZE_Y;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(console_handle, FALSE, &cfi);

    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = FALSE;
    cci.dwSize = 1;
    SetConsoleCursorInfo(console_handle, &cci);

    setConsoleWindowStyle(GWL_STYLE, new_style);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);


    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    SCREEN_WIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SCREEN_HEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    short OFFSET_X = SCREEN_WIDTH / 2 - GAME_WIDTH / 2;
    short OFFSET_Y = SCREEN_HEIGHT / 2 - GAME_HEIGHT / 2;


    bufferSize = { GAME_WIDTH,GAME_HEIGHT };
    bufferCoord = { 0, 0 };
    gameSpace = { OFFSET_X, OFFSET_Y, GAME_WIDTH - 1 + OFFSET_X, GAME_HEIGHT - 1 + OFFSET_Y };
    CHAR_INFO buffer[GAME_HEIGHT][GAME_WIDTH];


    ReadConsoleOutput(console_handle, (CHAR_INFO*)buffer, bufferSize, bufferCoord, &gameSpace);



}


void ENGINE_2D::update()
{

    for (int i = 0; i < GAME_WIDTH; ++i)
    {
        for (int j = 0; j < GAME_HEIGHT; ++j)
        {
            buffer[j][i].Char.UnicodeChar = 0x2584;
            buffer[j][i].Attributes = buffer[j][i].Attributes + 1 % 0xFF;
        }
    }

    assets[0][0]->Draw((CHAR_INFO**)buffer);


    WriteConsoleOutput(console_handle, (CHAR_INFO*)buffer, bufferSize, bufferCoord, &gameSpace);
    Sleep(500);
}