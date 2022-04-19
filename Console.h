#include "Header.h"

struct Console{

    // Remove blinking cursor
    void ShowConsoleCursor(bool showFlag)
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    // To change the Console Window Size
    void SetWindowSize(SHORT width, SHORT height)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SMALL_RECT WindowSize;
        WindowSize.Top = 0;
        WindowSize.Left = 0;
        WindowSize.Right = width;
        WindowSize.Bottom = height;

        SetConsoleWindowInfo(hStdout, 1, &WindowSize);
    }

    // To change Screen Buffer Size
    void SetScreenBufferSize(SHORT width, SHORT height)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD NewSize;
        NewSize.X = width;
        NewSize.Y = height;

        SetConsoleScreenBufferSize(hStdout, NewSize);
    }

    // Hide/Show the Scroll bar
    void Scrollbar(BOOL Show)
    {
        HWND hWnd = GetConsoleWindow();
        ShowScrollBar(hWnd, SB_BOTH, Show);
    }

    // To change the color of text
    void SetColor(int backgound_color, int text_color)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        int color_code = backgound_color * 16 + text_color;
        SetConsoleTextAttribute(hStdout, color_code);
    }

    void changecolour(int colour)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
    }

    // Move the cursor to poisition(x;y)
    void GotoXY(sh pX, sh pY)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {pX, pY};
        SetConsoleCursorPosition(hStdout, position);
    }

    void DisableResizeWindow()
    {
        HWND hWnd = GetConsoleWindow();
        SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
    }

    void DisableCtrButton(bool Close, bool Min, bool Max)
    {
        HWND hWnd = GetConsoleWindow();
        HMENU hMenu = GetSystemMenu(hWnd, false);
        
        if (Close == 1)
        {
            DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
        }
        if (Min == 1)
        {
            DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
        }
        if (Max == 1)
        {
            DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
        }
    }

} console;