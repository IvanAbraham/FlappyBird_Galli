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

	void Init(Tutorial::textureTutorial& background, bool& initiated);

	void Update(program::Screens& currentScreen, program::Button& backButton, Tutorial::textureTutorial& background, bool& initiated);

}