#include "renderer2D.h"


void RENDERER_2D::start()
{
    short SCREEN_WIDTH = 0, SCREEN_HEIGHT = 0;
    LONG_PTR new_style = WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL;
    LONG_PTR setConsoleWindowStyle(INT, LONG_PTR);

    console_handle = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX *cfi = new CONSOLE_FONT_INFOEX();
    cfi->cbSize = sizeof(cfi);
    cfi->nFont = 0;
    cfi->dwFontSize.X = FONT_SIZE_X;                   // Width of each character in the font
    cfi->dwFontSize.Y = FONT_SIZE_Y;                  // Height
    cfi->FontFamily = FF_DONTCARE;
    cfi->FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(console_handle, FALSE, cfi);
    free(cfi);

    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = FALSE;
    cci.dwSize = 1;
    SetConsoleCursorInfo(console_handle, &cci);

    RENDERER_2D::setConsoleWindowStyle(GWL_STYLE, new_style);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);


    CONSOLE_SCREEN_BUFFER_INFO* csbi = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), csbi);
    SCREEN_WIDTH = csbi->srWindow.Right - csbi->srWindow.Left + 1;
    SCREEN_HEIGHT = csbi->srWindow.Bottom - csbi->srWindow.Top + 1;

    short OFFSET_X = (SCREEN_WIDTH - GAME_WIDTH) >> 1;
    short OFFSET_Y = (SCREEN_HEIGHT - GAME_HEIGHT) >> 1;
    OFFSET_Y = 0;


    bufferSize = { GAME_WIDTH,GAME_HEIGHT };
    bufferCoord = { 0, 0 };
    gameSpace.Left = OFFSET_X;
    gameSpace.Top = OFFSET_Y;
    gameSpace.Right = GAME_WIDTH - 1 + OFFSET_X;
    gameSpace.Bottom = GAME_HEIGHT - 1 + OFFSET_Y;

    free(csbi);


    //ReadConsoleOutput(console_handle, (CHAR_INFO*)buffer, bufferSize, bufferCoord, &gameSpace);


    for (int i = 0; i < GAME_HEIGHT; i++)
    {
        for (int j = 0; j < GAME_WIDTH; j++)
        {
            buffer[i][j].Char.UnicodeChar = 0x2584;
            buffer[i][j].Attributes = 0xFF;
        }
    }


}


void RENDERER_2D::update()
{
    WriteConsoleOutput(console_handle, (CHAR_INFO*)buffer, bufferSize, bufferCoord, &gameSpace);
}


//Si le new style est à 0, la fenetre n'a absolument rien à part son contenu
LONG_PTR RENDERER_2D::setConsoleWindowStyle(INT n_index, LONG_PTR new_style)
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


void RENDERER_2D::writePixel(int coord_x, int coord_y, WORD color)
{
    if ((coord_x < 0 || coord_x >= PIXEL_HEIGHT) || (coord_y < 0 || coord_y >= PIXEL_WIDTH))
    {
        return;
    }
    if (coord_x % 2 != 1)
    {
        buffer[coord_x/2][coord_y].Attributes = (buffer[coord_x/2][coord_y].Attributes & 0x0F) | (color << 4);
    }
    else
    {
        buffer[coord_x/2][coord_y].Attributes = (buffer[coord_x/2][coord_y].Attributes & 0xF0) | color;
    }
}

void RENDERER_2D::writeChar(int coord_x, int coord_y, CHAR value, WORD color) {
    buffer[coord_x][coord_y].Char.UnicodeChar = value;
    buffer[coord_x][coord_y].Attributes = color;
}