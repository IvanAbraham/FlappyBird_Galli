#include "Program.h"
#include "Menu.h"
#include "Credits.h"
#include "Game.h"
#include "Tutorial.h"

namespace program
{
    int Start()
    {

        srand((unsigned int)time(nullptr));

        Screens actualScreen = Screens::Menu;

        InitWindow(screenWidth, screenHeight, "Flappy Bird");

        while (!WindowShouldClose())
        {
            switch (actualScreen)
            {
            case program::Screens::Menu:
                SetExitKey(KEY_ESCAPE);
                Menu::Update(actualScreen);
                break;
            case program::Screens::Game:
                SetExitKey(KEY_NULL);
                Game::Update(actualScreen);
                break;
            case program::Screens::Tutorial:
                SetExitKey(KEY_NULL);
                Tutorial::Update(actualScreen);
                break;
            case program::Screens::Credits:
                SetExitKey(KEY_NULL);
                Credits::Update(actualScreen);
                break;
            default:
                break;
            }
        }

        CloseWindow();
        return 0;
    }
}