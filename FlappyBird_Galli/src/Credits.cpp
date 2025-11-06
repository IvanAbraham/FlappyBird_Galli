#include "Credits.h"

namespace Credits
{
	int Update(program::Screens& actualScreen)
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			actualScreen = program::Screens::Menu;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Lucas Galli", program::screenWidth * 0.2, program::screenHeight * 0.5, program::screenWidth * 0.1, WHITE);
		EndDrawing();
		return 0;
	}
}