#define _WIN32_WINNT 0x0501
#include <stdio.h>
#include <windows.h>
#include <string.h>



#define GAME_WIDTH 350
#define GAME_HEIGHT 120
#define FONT_SIZE_X 3
#define FONT_SIZE_Y 6

int main()
{
    int SCREEN_WIDTH = 0, SCREEN_HEIGHT = 0;
    LONG_PTR new_style = WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL;
    LONG_PTR setConsoleWindowStyle(INT, LONG_PTR);

    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = FONT_SIZE_X;                   // Width of each character in the font
    cfi.dwFontSize.Y = FONT_SIZE_Y;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;


    SetCurrentConsoleFontEx(hOutput, FALSE, &cfi);
    setConsoleWindowStyle(GWL_STYLE, new_style);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    SCREEN_WIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SCREEN_HEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int OFFSET_X = SCREEN_WIDTH / 2 - GAME_WIDTH / 2;
    int OFFSET_Y = SCREEN_HEIGHT / 2 - GAME_HEIGHT / 2;


    COORD dwBufferSize = { GAME_WIDTH,GAME_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { OFFSET_X, OFFSET_Y, GAME_WIDTH - 1 + OFFSET_X, GAME_HEIGHT - 1 + OFFSET_Y };
    CHAR_INFO buffer[GAME_HEIGHT][GAME_WIDTH];


    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);



    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = FALSE;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);

    for (int i = 0; i < GAME_WIDTH; ++i)
    {
        for (int j = 0; j < GAME_HEIGHT; ++j)
        {
            buffer[j][i].Char.UnicodeChar = 0x2584;
            buffer[j][i].Attributes = 0x0F;
        }
    }

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
    while (true) {
        /*if (getc(stdin) == ' ')
        {
            return 0;
        }*/
        for (int i = 0; i < GAME_WIDTH; ++i)
        {
            for (int j = 0; j < GAME_HEIGHT; ++j)
            {
                buffer[j][i].Attributes = buffer[j][i].Attributes +1 % 0xFF;
            }
        }
        WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
        Sleep(100);

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