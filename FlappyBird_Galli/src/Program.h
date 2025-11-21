#pragma once
#include <iostream>
#include "raylib.h"
#include <ctime>

namespace program
{

	const int screenWidth = 1280;
	const int screenHeight = 720;

	enum class Screens
	{
		Menu,
		Game,
		Credits,
		Tutorial
	};

	struct Button
	{
		Texture2D texture;
		Texture2D hovTexture;
		Vector2 position = {0, 0};
		Vector2 size = { program::screenWidth * 0.2, program::screenHeight * 0.1 };
		
		const char* text;
		float fontSize = static_cast<float>(program::screenHeight * 0.06);
		float textLength;

		bool isHovering = false;
		bool wasHovering = false;

	};

	int Start();

	
}