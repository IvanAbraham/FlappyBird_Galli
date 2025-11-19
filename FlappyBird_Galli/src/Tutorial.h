#pragma once

#include "Program.h"
#include "Game.h"

namespace Tutorial
{

	struct textureTutorial
	{
		Texture2D texture;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
	};

	void Init(textureTutorial& background);

	void Update(program::Screens& currentScreen, program::Button& backButton, textureTutorial& background);

}