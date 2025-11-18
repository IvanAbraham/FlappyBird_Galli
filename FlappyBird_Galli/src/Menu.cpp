#include "Menu.h"

namespace Menu
{	
	static void buttonLogic(program::Button& button)
	{
		if (col::pointToRect(GetMousePosition(),button.position,button.size))
		{
			button.isHovering = true;
		}
		else
		{

			button.isHovering = false;

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

	void Init(Menu::Buttons& buttons, Menu::textureMenu& background)
	{	

		buttons.playButton.position = { 10, program::screenHeight * 0.55f };
		buttons.playButton.text = "Play";
		buttons.playButton.textLength = static_cast<float>(MeasureText(buttons.playButton.text, static_cast<int>(buttons.playButton.fontSize)));

		buttons.twoPlayers.position = { buttons.playButton.position.x, buttons.playButton.position.y + buttons.twoPlayers.size.y + 10 };
		buttons.twoPlayers.text = "Two Players";
		buttons.twoPlayers.textLength = static_cast<float>(MeasureText(buttons.twoPlayers.text, static_cast<int>(buttons.twoPlayers.fontSize)));

		buttons.tutorial.position = { buttons.playButton.position.x, buttons.twoPlayers.position.y + buttons.creditsButton.size.y + 10 };
		buttons.tutorial.text = "Tutorial";
		buttons.tutorial.textLength = static_cast<float>(MeasureText(buttons.tutorial.text, static_cast<int>(buttons.tutorial.fontSize)));

		buttons.creditsButton.position = { buttons.playButton.position.x, buttons.tutorial.position.y + buttons.tutorial.size.y + 10 };
		buttons.creditsButton.text = "Credits";
		buttons.creditsButton.textLength = static_cast<float>(MeasureText(buttons.creditsButton.text, static_cast<int>(buttons.creditsButton.fontSize)));

		background.texture = LoadTexture("res/Textures/MainMenu/Menu1.png");
		background.source = { 0, 0, static_cast<float>(background.texture.width), static_cast<float>(background.texture.height) };
		background.dest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
		background.origin = { 0, 0 };
	}

	void Update(program::Screens& actualScreen, textureMenu& background, Menu::Buttons& buttons)
	{

		buttonLogic(buttons.playButton);
		buttonLogic(buttons.twoPlayers);
		buttonLogic(buttons.tutorial);
		buttonLogic(buttons.creditsButton);

		if (buttons.playButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		
			actualScreen = program::Screens::Game;
			Game::twoPlayers = false;

			
		
		}

		if (buttons.twoPlayers.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			actualScreen = program::Screens::Game;
			Game::twoPlayers = true;

		}

		if (buttons.tutorial.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			actualScreen = program::Screens::Tutorial;

		}

		if (buttons.creditsButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualScreen = program::Screens::Credits;
		}

		BeginDrawing();
		
		DrawTexturePro(background.texture, background.source, background.dest, background.origin, 0.0f, WHITE);

		buttonDraw(buttons.playButton);
		buttonDraw(buttons.twoPlayers);
		buttonDraw(buttons.tutorial);
		buttonDraw(buttons.creditsButton);

		DrawText(buttons.playButton.text, static_cast<int>(buttons.playButton.position.x), static_cast<int>(buttons.playButton.position.y + buttons.playButton.fontSize / 2), static_cast<int>(buttons.playButton.fontSize), BLACK);
		DrawText(buttons.twoPlayers.text, static_cast<int>(buttons.twoPlayers.position.x), static_cast<int>(buttons.twoPlayers.position.y + buttons.twoPlayers.fontSize / 2), static_cast<int>(buttons.twoPlayers.fontSize), BLACK);
		DrawText(buttons.tutorial.text, static_cast<int>(buttons.tutorial.position.x), static_cast<int>(buttons.tutorial.position.y + buttons.tutorial.fontSize / 2), static_cast<int>(buttons.tutorial.fontSize), BLACK);
		DrawText(buttons.creditsButton.text, static_cast<int>(buttons.creditsButton.position.x), static_cast<int>(buttons.creditsButton.position.y + buttons.creditsButton.fontSize / 2), static_cast<int>(buttons.creditsButton.fontSize), BLACK);
		
		DrawText("0.4", 5, 5, static_cast<int>(program::screenHeight * 0.06), RED);
		
		EndDrawing();

	}
}