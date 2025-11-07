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
		DrawText("Lucas Galli", (float)program::screenWidth * 0.2, (float)program::screenHeight * 0.5, (float)program::screenWidth * 0.1, WHITE);
		DrawText("0.3", program::screenWidth-20, 5, 10, WHITE);
		EndDrawing();
		return 0;
	}
}