#pragma once
#include "Game.h"

namespace player
{
	struct Player
	{
		Vector2 position{ 0 };
		Vector2 size = { 40,40 };
		float acceleration = 0;
		bool isAlive = true;
	};

	void Movement(Player& player);

	void MovmentP2(Player& player);
}