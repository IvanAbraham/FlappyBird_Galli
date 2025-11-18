#include "Credits.h"

namespace Credits
{

	int Update(program::Screens& actualScreen)
	{

		const char* ogAuthorTxt = "Original author: Lucas Galli";
		const char* upAuthorTxt = "Ver 0.4 forward author: Ivan Abraham";

		const float fontSize = static_cast<float>(program::screenHeight * 0.06);
		const float gap = program::screenHeight * 0.1;

		program::Button backButton;

		backButton.position = { 5,5 };
		backButton.text = "Back";
		backButton.textLength = static_cast<float>(MeasureText(backButton.text, static_cast<int>(backButton.fontSize)));
		backButton.size = { backButton.textLength + 5, 50 };

		if (IsKeyPressed(KEY_ESCAPE))
		{
			actualScreen = program::Screens::Menu;
		}
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
		ClearBackground(BLACK);
		
		if (backButton.isHovering)
		{
			DrawRectangleV(backButton.position, backButton.size, GRAY);
		}
		else
		{
			DrawRectangleV(backButton.position,backButton.size,WHITE);
		}

		DrawText(backButton.text, static_cast<int>(backButton.position.x), static_cast<int>(backButton.position.y), static_cast<int>(fontSize), BLACK);
		
		DrawText(ogAuthorTxt, static_cast<int>(program::screenWidth * 0.1), static_cast<int>(program::screenHeight * 0.3), static_cast<int>(fontSize), WHITE);
		DrawText(upAuthorTxt, static_cast<int>(program::screenWidth * 0.1), static_cast<int>(program::screenHeight * 0.3 + fontSize + gap), static_cast<int>(fontSize), WHITE);
		
		EndDrawing();
		
		return 0;
	}
}