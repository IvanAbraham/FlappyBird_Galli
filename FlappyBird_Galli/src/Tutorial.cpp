#include "Tutorial.h"

namespace Tutorial
{

	void Update(program::Screens& currentScreen)
	{

		program::Button p1Title;
		program::Button p2Title;

		program::Button p1Tutorial;
		program::Button p2Tutorial;

		p1Title.text = "Player 1 or Singleplayer:";
		p1Title.textLength = static_cast<float>(MeasureText(p1Title.text, static_cast<int>(p1Title.fontSize)));
		p1Title.position = { static_cast<float>(program::screenWidth * 0.01), program::screenHeight * 0.25 };

		p1Tutorial.text = "If you're playing alone or are the p1 press \"W\" to jump.";
		p1Tutorial.textLength = static_cast<float>(MeasureText(p1Tutorial.text, static_cast<int>(p1Tutorial.fontSize)));
		p1Tutorial.position = {p1Title.position.x, p1Title.position.y + p1Title.fontSize + 10.0f};
		p1Tutorial.fontSize = static_cast<float>(program::screenHeight) * 0.03f;

		p2Title.text = "Player 2:";
		p2Title.position = { p1Title.position.x + 10.0f, p1Tutorial.position.y + p2Title.fontSize + 10.0f };
		
		p2Tutorial.text = "If you're the second player, press \"ARROW UP\" to jump.";
		p2Tutorial.textLength = static_cast<float>(MeasureText(p2Tutorial.text, static_cast<int>(p2Tutorial.fontSize)));
		p2Tutorial.position = { p2Title.position.x, p2Title.position.y + p2Title.fontSize + 10.0f };
		p2Tutorial.fontSize = static_cast<float>(program::screenHeight) * 0.03f;

		const float fontSize = static_cast<float>(program::screenHeight * 0.06);

		program::Button backButton;

		backButton.position = { 5,5 };
		backButton.text = "Back";
		backButton.textLength = static_cast<float>(MeasureText(backButton.text, static_cast<int>(backButton.fontSize)));
		backButton.size = { backButton.textLength + 5, 50 };

		if (IsKeyPressed(KEY_ESCAPE))
		{

			currentScreen = program::Screens::Menu;

		}
		if (col::pointToRect(GetMousePosition(), backButton.position, backButton.size))
		{
			backButton.isHovering = true;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				currentScreen = program::Screens::Menu;
			}
		}

		BeginDrawing();
		ClearBackground(BLACK);

		if (backButton.isHovering)
		{
			DrawRectangleV(backButton.position, backButton.size, GRAY);
		}
		else
		{
			DrawRectangleV(backButton.position, backButton.size, WHITE);
		}

		DrawText(backButton.text, static_cast<int>(backButton.position.x), static_cast<int>(backButton.position.y), static_cast<int>(fontSize), BLACK);
		
		DrawText(p1Title.text, static_cast<int>(p1Title.position.x), static_cast<int>(p1Title.position.y), static_cast<int>(p1Title.fontSize), WHITE);
		DrawText(p1Tutorial.text, static_cast<int>(p1Tutorial.position.x), static_cast<int>(p1Tutorial.position.y), static_cast<int>(p1Tutorial.fontSize), WHITE);

		DrawText(p2Title.text, static_cast<int>(p2Title.position.x), static_cast<int>(p2Title.position.y), static_cast<int>(p2Title.fontSize), SKYBLUE);
		DrawText(p2Tutorial.text, static_cast<int>(p2Tutorial.position.x), static_cast<int>(p2Tutorial.position.y), static_cast<int>(p2Tutorial.fontSize), SKYBLUE);

		EndDrawing();


	}

}