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

        Menu::Buttons menuButtons;
        Menu::textureMenu menuTexture;

        Credits::textureCredits creditsTexture;
        
        Button backButton;

        InitWindow(screenWidth, screenHeight, "Flappy Bird");  

        Menu::Init(menuButtons, menuTexture);
        Credits::Init(backButton, creditsTexture);

        while (!WindowShouldClose())
        {
            switch (actualScreen)
            {
            case program::Screens::Menu:
                
                Menu::Update(actualScreen, menuTexture, menuButtons);
                
                break;
            
            case program::Screens::Game:
               
                Game::Update(actualScreen);
                break;
            
            case program::Screens::Tutorial:
            
                SetExitKey(KEY_NULL);
                Tutorial::Update(actualScreen);
                
                break;
            
            case program::Screens::Credits:
            
                SetExitKey(KEY_NULL);
                Credits::Update(actualScreen, creditsTexture, backButton);
                
                break;
            
            default:
            
                break;
            }
        }

        CloseWindow();
        return 0;
    }
}