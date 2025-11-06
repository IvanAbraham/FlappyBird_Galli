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

	int Start();
}