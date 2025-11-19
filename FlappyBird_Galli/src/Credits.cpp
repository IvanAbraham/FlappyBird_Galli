#include "Credits.h"

namespace Credits
{

	void Init(textureCredits& background)
	{
		
		background.texture = LoadTexture("res/Textures/Credits/Credits1.png");
		background.source = { 0, 0, static_cast<float>(background.texture.width), static_cast<float>(background.texture.height) };
		background.dest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
		background.origin = { 0, 0 };
	}

	int Update(program::Screens& actualScreen, Credits::textureCredits& background, program::Button backButton)
	{

		if (col::pointToRect(GetMousePosition(),backButton.position,backButton.size))
		{
			backButton.isHovering = true;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				actualScreen = program::Screens::Menu;
			}
		}
		else
		{
			backButton.isHovering = false;
		}

		BeginDrawing();
		
		DrawTexturePro(background.texture, background.source, background.dest, background.origin, 0.0f, WHITE);

		if (backButton.isHovering)
		{
			DrawTexture(backButton.hovTexture, static_cast<int>(backButton.position.x), static_cast<int>(backButton.position.y), WHITE);
		}
		else
		{
			DrawTexture(backButton.texture, static_cast<int>(backButton.position.x), static_cast<int>(backButton.position.y), WHITE);
		}
		
		EndDrawing();
		
		return 0;
	}
}