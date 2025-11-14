#include "Credits.h"

namespace Credits
{
	int Update(program::Screens& actualScreen)
	{
		program::Button backButton;

		backButton.Position = { 5,5 };
		backButton.Size = { 50,50 };


		if (IsKeyPressed(KEY_ESCAPE))
		{
			actualScreen = program::Screens::Menu;
		}
		if (col::pointToRect(GetMousePosition(),backButton.Position,backButton.Size))
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
		ClearBackground(BLACK);
		if (backButton.isHovering)
		{
			DrawRectangleV(backButton.Position, backButton.Size, GRAY);
		}
		else
		{
			DrawRectangleV(backButton.Position,backButton.Size,WHITE);
		}
		DrawText("Autor original: Lucas Galli", static_cast<int>(program::screenWidth * 0.1), static_cast<int>(program::screenHeight * 0.3), static_cast<int>(program::screenHeight * 0.05), WHITE);
		DrawText("Version < 0.4: Ivan Abraham", static_cast<int>(program::screenWidth * 0.1), static_cast<int>(program::screenHeight * 0.5), static_cast<int>(program::screenHeight * 0.05), WHITE);
		DrawText("0.4", program::screenWidth-20, 5, 1, WHITE);
		EndDrawing();
		return 0;
	}
}