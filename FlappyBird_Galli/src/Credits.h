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

	int Update(program::Screens& actualScreen, Credits::textureCredits& background, program::Button backButton, bool& initiated);
	void Init(textureCredits& background, bool& initiated);
}