#pragma once
#include "Program.h"
#include "Game.h"

namespace Credits
{
	struct Button
	{
		Vector2 Position;
		Vector2 Size = { program::screenWidth * 0.2, program::screenHeight * 0.1 };
		bool isHovering = false;
	};

	struct textureCredits
	{

		Texture2D texture;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;

	};

	int Update(program::Screens& actualScreen);
}