#include "Menu.h"

namespace Menu
{
	static void buttonLogic(program::Button& button)
	{
		if (col::pointToRect(GetMousePosition(),button.position,button.size))
		{
			button.isHovering = true;
		}
	}

	static void buttonDraw(program::Button& button)
	{
		if (button.isHovering)
		{
			DrawRectangleV(button.position, button.size, GRAY);
		}
		else
		{
			DrawRectangleV(button.position, button.size, WHITE);
		}
	}

	int Update(program::Screens& actualScreen)
	{
		program::Button playButton;
		program::Button twoPlayers;
		program::Button creditsButton;

		playButton.position = { program::screenWidth * 0.4, program::screenHeight * 0.4 };
		playButton.text = "Play";
		playButton.textLength = static_cast<float>(MeasureText(playButton.text, static_cast<int>(playButton.fontSize)));

		twoPlayers.position = { program::screenWidth * 0.4, playButton.position.y + twoPlayers.size.y + 10 };
		twoPlayers.text = "Two Players";
		twoPlayers.textLength = static_cast<float>(MeasureText(twoPlayers.text, static_cast<int>(twoPlayers.fontSize)));

		creditsButton.position = { program::screenWidth * 0.4, twoPlayers.position.y + creditsButton.size.y + 10 };
		creditsButton.text = "Credits";
		creditsButton.textLength = static_cast<float>(MeasureText(creditsButton.text, static_cast<int>(creditsButton.fontSize)));

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

		DrawText(playButton.text, static_cast<int>(playButton.position.x) + static_cast<int>(playButton.textLength / 2), static_cast<int>(playButton.position.y) + static_cast<int>(playButton.fontSize / 2), static_cast<int>(playButton.fontSize), BLACK);
		DrawText(twoPlayers.text, static_cast<int>(twoPlayers.position.x), static_cast<int>(twoPlayers.position.y) + static_cast<int>(twoPlayers.fontSize / 2), static_cast<int>(twoPlayers.fontSize), BLACK);
		DrawText(creditsButton.text, static_cast<int>(creditsButton.position.x) + static_cast<int>(creditsButton.textLength / 2), static_cast<int>(creditsButton.position.y) + static_cast<int>(creditsButton.fontSize / 2), static_cast<int>(creditsButton.fontSize), BLACK);
		
		DrawText("0.4", 5, 5, 10, RED);
		
		EndDrawing();
		
		return 0;
	}
}