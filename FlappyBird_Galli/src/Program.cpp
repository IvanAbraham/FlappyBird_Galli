#include "Game.h"
#include "Menu.h"
#include "Credits.h"

namespace program
{
    int Start()
    {
        srand((unsigned int)time(nullptr));

        Screens actualScreen = Screens::Game;

        InitWindow(screenWidth, screenHeight, "Flappy Bird");

        while (!WindowShouldClose())
        {
            switch (actualScreen)
            {
            case program::Screens::Menu:
                Menu::Update(actualScreen);
                break;
            case program::Screens::Game:
                Game::Update(actualScreen);
                break;
            case program::Screens::Credits:
                //Credits::Update(actualScreen);
                break;
            default:
                break;
            }
        }

        CloseWindow();
        return 0;
    }
}