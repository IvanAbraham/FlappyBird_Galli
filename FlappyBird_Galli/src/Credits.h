#pragma once
#include "Program.h"
#include "Game.h"

namespace Credits
{

	struct textureCredits
	{
		Texture2D texture;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
	};

	int Update(program::Screens& actualScreen, textureCredits& background, program::Button backButton);

	void Init(program::Button backButton, textureCredits& background);
}