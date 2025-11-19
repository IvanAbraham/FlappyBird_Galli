#include "Tutorial.h"

namespace Tutorial
{

	void Init(Tutorial::textureTutorial& background)
	{

		background.texture = LoadTexture("res/Textures/Tutorial/Tutorial1.png");
		background.source = { 0, 0, static_cast<float>(background.texture.width), static_cast<float>(background.texture.height) };
		background.dest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
		background.origin = { 0, 0 };

	}

	void Update(program::Screens& currentScreen, program::Button& backButton, Tutorial::textureTutorial& background)
	{

		if (IsKeyPressed(KEY_ESCAPE))
			currentScreen = program::Screens::Menu;
		
		if (col::pointToRect(GetMousePosition(), backButton.position, backButton.size))
		{
			backButton.isHovering = true;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				currentScreen = program::Screens::Menu;
			}
		}

		BeginDrawing();
		
		DrawTexturePro(background.texture, background.source, background.dest, background.origin, 0.0f, WHITE);

		if (backButton.isHovering)
			DrawRectangleV(backButton.position, backButton.size, GRAY);

		else
			DrawRectangleV(backButton.position, backButton.size, WHITE);

		EndDrawing();


	}

}