#include "Game.h"

int main()
{
    HWND consoleWindow = GetConsoleWindow();
    SetWindowPos( consoleWindow, 0, 450, 150, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
    console.SetWindowSize(119,47);
    console.Scrollbar(0);
    console.DisableResizeWindow();
    console.DisableCtrButton(0,0,1);
    pikachu **board;
    Menu(board);
    delete[] board;
    system("pause");
    return 0;
}