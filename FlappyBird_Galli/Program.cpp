#include "Program.h"
#include "../src/Game.h"

int Start()
{
    srand((unsigned int)time(nullptr));

	Screens actualScreen = Screens::Menu;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    while (!WindowShouldClose())
    {
        switch (actualScreen)
        {
        case Screens::Menu:
            break;
        case Screens::Game:
            Game();
            break;
        case Screens::Credits:
            break;
        default:
            break;
        }
    }

    CloseWindow();
    return 0;
}