#include "Menu.h"

namespace Menu
{

	Music menuMusic;

	static void buttonLogic(program::Button& button)
	{
		bool currentlyHovering = col::pointToRect(GetMousePosition(), button.position, button.size);

		button.wasHovering = button.isHovering;      
		button.isHovering = currentlyHovering;

	}

	static void buttonDraw(program::Button& button, Sound sound)
	{
		if (button.isHovering && !button.wasHovering)
		{
			PlaySound(sound);
		}

		if (button.isHovering)
		{
			DrawTexture(button.hovTexture, static_cast<int>(button.position.x), static_cast<int>(button.position.y), WHITE);
		}
		else
		{
			DrawTexture(button.texture, static_cast<int>(button.position.x), static_cast<int>(button.position.y), WHITE);
		}
	}

	void Init(Menu::Buttons& buttons, Menu::textureMenu& background, bool& initiated)
	{
		if (!initiated)
		{
			menuMusic = LoadMusicStream("res/Music/inspiring-motivation-synthwave-2-421075.mp3");
			PlayMusicStream(menuMusic);

			buttons.hoverSound = LoadSound("res/Sfx/Hover.mp3");
			buttons.selectSound = LoadSound("res/Sfx/Click.mp3");

			buttons.playButton.texture = LoadTexture("res/Textures/Buttons/Play.png");
			buttons.playButton.hovTexture = LoadTexture("res/Textures/Buttons/PlaySelec.png");
			buttons.playButton.position = { 10, program::screenHeight * 0.52f };

			buttons.twoPlayers.texture = LoadTexture("res/Textures/Buttons/2Players.png");
			buttons.twoPlayers.hovTexture = LoadTexture("res/Textures/Buttons/2PlayersSelec.png");
			buttons.twoPlayers.position = { buttons.playButton.position.x, buttons.playButton.position.y + buttons.twoPlayers.size.y };

			buttons.tutorial.texture = LoadTexture("res/Textures/Buttons/Tutorial.png");
			buttons.tutorial.hovTexture = LoadTexture("res/Textures/Buttons/TutorialSelec.png");
			buttons.tutorial.position = { buttons.playButton.position.x, buttons.twoPlayers.position.y + buttons.creditsButton.size.y };

			buttons.creditsButton.texture = LoadTexture("res/Textures/Buttons/Credits.png");
			buttons.creditsButton.hovTexture = LoadTexture("res/Textures/Buttons/CreditsSelec.png");
			buttons.creditsButton.position = { buttons.playButton.position.x, buttons.tutorial.position.y + buttons.tutorial.size.y };

			buttons.quitButton.texture = LoadTexture("res/Textures/Buttons/Quit.png");
			buttons.quitButton.hovTexture = LoadTexture("res/Textures/Buttons/QuitSelec.png");
			buttons.quitButton.position = { program::screenWidth - buttons.quitButton.size.x, buttons.tutorial.position.y + buttons.tutorial.size.y };

			background.texture = LoadTexture("res/Textures/MainMenu/Menu1.png");
			background.source = { 0, 0, static_cast<float>(background.texture.width), static_cast<float>(background.texture.height) };
			background.dest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
			background.origin = { 0, 0 };

			initiated = true;
		}
	}

	void UnloadTextures(textureMenu& background, Menu::Buttons& buttons, bool& initiated)
	{
		UnloadTexture(buttons.playButton.texture);
		UnloadTexture(buttons.playButton.hovTexture);

		UnloadTexture(buttons.twoPlayers.texture);
		UnloadTexture(buttons.twoPlayers.hovTexture);

		UnloadTexture(buttons.tutorial.texture);
		UnloadTexture(buttons.tutorial.hovTexture);

		UnloadTexture(buttons.creditsButton.texture);
		UnloadTexture(buttons.creditsButton.hovTexture);

		UnloadTexture(buttons.quitButton.texture);
		UnloadTexture(buttons.quitButton.hovTexture);

		UnloadTexture(background.texture);

		initiated = false;

	}

	void Update(program::Screens& actualScreen, textureMenu& background, Menu::Buttons& buttons, bool& isPlaying, bool& initiated)
	{
		UpdateMusicStream(menuMusic);

		buttonLogic(buttons.playButton);
		buttonLogic(buttons.twoPlayers);
		buttonLogic(buttons.tutorial);
		buttonLogic(buttons.creditsButton);
		buttonLogic(buttons.quitButton);

		if (buttons.playButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(buttons.selectSound);

			actualScreen = program::Screens::Game;
			
			Game::twoPlayers = false;
			
			UnloadTextures(background, buttons, initiated);
			UnloadMusicStream(menuMusic);
		}

		if (buttons.twoPlayers.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(buttons.selectSound);

			actualScreen = program::Screens::Game;
			
			Game::twoPlayers = true;
			
			UnloadTextures(background, buttons, initiated);
			UnloadMusicStream(menuMusic);
		}

		if (buttons.tutorial.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(buttons.selectSound);
			
			actualScreen = program::Screens::Tutorial;
			
			UnloadTextures(background, buttons, initiated);
			UnloadMusicStream(menuMusic);
		}

		if (buttons.creditsButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(buttons.selectSound);

			actualScreen = program::Screens::Credits;
			
			UnloadTextures(background, buttons, initiated);
			UnloadMusicStream(menuMusic);
		}

		if (buttons.quitButton.isHovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(buttons.selectSound);

			UnloadTextures(background, buttons, initiated);
			UnloadMusicStream(menuMusic);
			isPlaying = false;
		}

		BeginDrawing();
		
		DrawTexturePro(background.texture, background.source, background.dest, background.origin, 0.0f, WHITE);

		buttonDraw(buttons.playButton, buttons.hoverSound);
		buttonDraw(buttons.twoPlayers, buttons.hoverSound);
		buttonDraw(buttons.tutorial, buttons.hoverSound);
		buttonDraw(buttons.creditsButton, buttons.hoverSound);
		buttonDraw(buttons.quitButton, buttons.hoverSound);
		
		
		DrawText("0.4", 5, 5, static_cast<int>(program::screenHeight * 0.06), RED);
		
		EndDrawing();

	}
}