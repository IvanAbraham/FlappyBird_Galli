#pragma once
#include "Program.h"
#include "Game.h"



namespace Menu
{
	struct Buttons
	{
		program::Button playButton;
		program::Button twoPlayers;
		program::Button tutorial;
		program::Button creditsButton;
	};
	
	struct textureMenu
	{

		Texture2D texture;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;

	};

	void Update(program::Screens& actualScreen, textureMenu& background, Menu::Buttons& buttons);
	void Init(Menu::Buttons& buttons, Menu::textureMenu& background);
}