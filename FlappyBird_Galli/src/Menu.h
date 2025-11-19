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
		program::Button quitButton;
	};
	
	struct textureMenu
	{

		Texture2D texture;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;

	};

	void Update(program::Screens& actualScreen, textureMenu& background, Menu::Buttons& buttons, bool& isPlaying);
	void Init(Menu::Buttons& buttons, Menu::textureMenu& background);

}