#include "Game.h"
#include "Menu.h"
#include "Credits.h"

int Start()
{
    srand((unsigned int)time(nullptr));

	Screens actualScreen = Screens::Game;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    while (!WindowShouldClose())
    {
        switch (actualScreen)
        {
        case Screens::Menu:
            Menu::Update();
            break;
        case Screens::Game:
            Game::Update();
            break;
        case Screens::Credits:
            Credits::Update();
            break;
        default:
            break;
        }
    }

    CloseWindow();
    return 0;
}