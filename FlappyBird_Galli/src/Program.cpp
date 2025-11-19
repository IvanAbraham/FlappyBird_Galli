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
        
        Tutorial::textureTutorial tutorialTexture;

        Button backButton;

        InitWindow(screenWidth, screenHeight, "Flappy Bird");  

        backButton.textLength = static_cast<float>(program::screenWidth / 6), static_cast<int>(program::screenHeight / 6);
        backButton.size = { backButton.textLength + 5, 50 };
        backButton.position = { static_cast<float>(program::screenWidth - backButton.size.x), static_cast<float> (program::screenHeight - backButton.size.y * 2) };
        backButton.texture = LoadTexture("res/Textures/Buttons/Back.png");
        backButton.hovTexture = LoadTexture("res/Textures/Buttons/BackSelec.png");

        bool isPlaying = true;

        Menu::Init(menuButtons, menuTexture);
        Credits::Init(creditsTexture);
        Tutorial::Init(tutorialTexture);

        while (!WindowShouldClose() && isPlaying)
        {
            switch (actualScreen)
            {
            case program::Screens::Menu:
                
                Menu::Update(actualScreen, menuTexture, menuButtons, isPlaying);
                
                break;
            
            case program::Screens::Game:
               
                Game::Update(actualScreen);
                break;
            
            case program::Screens::Tutorial:
            
                SetExitKey(KEY_NULL);
                Tutorial::Update(actualScreen, backButton, tutorialTexture);
                
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