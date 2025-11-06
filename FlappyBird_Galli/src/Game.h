#pragma once
#include "Program.h"
#include "Player.h"
#include "Obstacle.h"
#include "Collisions.h"

namespace Game
{
	static float speed = 200.0f;

	void Update(program::Screens& actualScreen);
}