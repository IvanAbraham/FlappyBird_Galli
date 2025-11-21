#pragma once
#include "Game.h"

namespace player
{
	struct Player
	{
		Vector2 position{ 0 };
		Vector2 size = { static_cast<int>(program::screenWidth * 0.08), static_cast<int>(program::screenHeight * 0.1) };
		float acceleration = 0;
		bool isAlive = true;
	};

	void Movement(Player& player);

	void MovmentP2(Player& player);
}