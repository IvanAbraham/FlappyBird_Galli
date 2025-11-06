#pragma once
#include "Game.h"
namespace obstacle
{
	struct Obstacle
	{
		Vector2 position{ 0 };
		Vector2 size = { 40,screenHeight };
	};
	void Movement(Obstacle obstacle[2]);
}