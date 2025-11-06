#include "Menu.h"

namespace Menu
{
	static void buttonLogic(Menu::Button& button)
	{
		if (col::pointToRect(GetMousePosition(),button.Position,button.Size))
		{
			button.isHovering = true;
		}
	}

	static void buttonDraw(Menu::Button& button)
	{
		if (button.isHovering)
		{
			DrawRectangleV(button.Position, button.Size, GRAY);
		}
		else
		{
			DrawRectangleV(button.Position, button.Size, WHITE);
		}
	}

	int Update(program::Screens& actualScreen)
	{
		Menu::Button playButton;
		Menu::Button creditsButton;

		playButton.Position = { program::screenWidth * 0.4, program::screenHeight * 0.6 };
		creditsButton.Position = { program::screenWidth * 0.4, program::screenHeight * 0.75 };

		buttonLogic(playButton);
		buttonLogic(creditsButton);

		if (playButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualScreen = program::Screens::Game;
		}
		if (creditsButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualScreen = program::Screens::Credits;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		buttonDraw(playButton);
		buttonDraw(creditsButton);

		EndDrawing();
		
		return 0;
	}
}