#pragma once
#include <iostream>
#include "raylib.h"
#include <ctime>

namespace program
{

	const int screenWidth = 800;
	const int screenHeight = 450;

	enum class Screens
	{
		Menu,
		Game,
		Credits
	};

	struct Button
	{
		Vector2 Position = {0,0};
		Vector2 Size = { program::screenWidth * 0.2, program::screenHeight * 0.1 };
		bool isHovering = false;
	};

	int Start();
}