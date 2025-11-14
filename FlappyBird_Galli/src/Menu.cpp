#include "Menu.h"

namespace Menu
{
	static void buttonLogic(program::Button& button)
	{
		if (col::pointToRect(GetMousePosition(),button.Position,button.Size))
		{
			button.isHovering = true;
		}
	}

	static void buttonDraw(program::Button& button)
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
		program::Button playButton;
		program::Button twoPlayers;
		program::Button creditsButton;

		playButton.Position = { program::screenWidth * 0.4, program::screenHeight * 0.4 };
		twoPlayers.Position = { program::screenWidth * 0.4, playButton.Position.y + twoPlayers.Size.y + 10 };
		creditsButton.Position = { program::screenWidth * 0.4, twoPlayers.Position.y + creditsButton.Size.y + 10 };

		buttonLogic(playButton);
		buttonLogic(twoPlayers);
		buttonLogic(creditsButton);

		if (playButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		
			actualScreen = program::Screens::Game;
			Game::twoPlayers = false;
		
		}

		if (twoPlayers.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			actualScreen = program::Screens::Game;
			Game::twoPlayers = true;

		}

		if (creditsButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualScreen = program::Screens::Credits;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		buttonDraw(playButton);
		buttonDraw(twoPlayers);
		buttonDraw(creditsButton);

		DrawText("Play", static_cast<int>(playButton.Position.x) + 20, static_cast<int>(playButton.Position.y), 20, BLACK);
		DrawText("Two Players", static_cast<int>(twoPlayers.Position.x) + 20, static_cast<int>(twoPlayers.Position.y), 20, BLACK);
		DrawText("Credits", static_cast<int>(creditsButton.Position.x) + 20, static_cast<int>(creditsButton.Position.y), 20, BLACK);
		DrawText("0.4", 5, 5, 10, RED);
		EndDrawing();
		
		return 0;
	}
}