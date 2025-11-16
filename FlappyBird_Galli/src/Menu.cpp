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
		program::Button tutorial;
		program::Button creditsButton;

		playButton.position = { 10, program::screenHeight * 0.4 };
		playButton.text = "Play";
		playButton.textLength = static_cast<float>(MeasureText(playButton.text, static_cast<int>(playButton.fontSize)));

		twoPlayers.position = { playButton.position.x, playButton.position.y + twoPlayers.size.y + 10 };
		twoPlayers.text = "Two Players";
		twoPlayers.textLength = static_cast<float>(MeasureText(twoPlayers.text, static_cast<int>(twoPlayers.fontSize)));

		tutorial.position = { playButton.position.x, twoPlayers.position.y + creditsButton.size.y + 10 };
		tutorial.text = "Tutorial";
		tutorial.textLength = static_cast<float>(MeasureText(tutorial.text, static_cast<int>(tutorial.fontSize)));

		creditsButton.position = { playButton.position.x, tutorial.position.y + tutorial.size.y + 10 };
		creditsButton.text = "Credits";
		creditsButton.textLength = static_cast<float>(MeasureText(creditsButton.text, static_cast<int>(creditsButton.fontSize)));

		buttonLogic(playButton);
		buttonLogic(twoPlayers);
		buttonLogic(tutorial);
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

		if (tutorial.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			actualScreen = program::Screens::Tutorial;

		}

		if (creditsButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualScreen = program::Screens::Credits;
		}

		BeginDrawing();
		
		ClearBackground(BLACK);
		
		buttonDraw(playButton);
		buttonDraw(twoPlayers);
		buttonDraw(tutorial);
		buttonDraw(creditsButton);

		DrawText(playButton.text, static_cast<int>(playButton.position.x), static_cast<int>(playButton.position.y + playButton.fontSize / 2), static_cast<int>(playButton.fontSize), BLACK);
		DrawText(twoPlayers.text, static_cast<int>(twoPlayers.position.x), static_cast<int>(twoPlayers.position.y + twoPlayers.fontSize / 2), static_cast<int>(twoPlayers.fontSize), BLACK);
		DrawText(tutorial.text, static_cast<int>(tutorial.position.x), static_cast<int>(tutorial.position.y + tutorial.fontSize / 2), static_cast<int>(tutorial.fontSize), BLACK);
		DrawText(creditsButton.text, static_cast<int>(creditsButton.position.x), static_cast<int>(creditsButton.position.y + creditsButton.fontSize / 2), static_cast<int>(creditsButton.fontSize), BLACK);
		
		DrawText("0.4", 5, 5, static_cast<int>(program::screenHeight * 0.06), RED);
		
		EndDrawing();
		
		return 0;
	}
}