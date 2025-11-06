#pragma once
#include "Game.h"

namespace col
{
	bool rectToRect(Vector2 Rect1, Vector2 Rect1Size, Vector2 Rect2, Vector2 Rect2Size);

	bool pointToRect(Vector2 point, Vector2 Rect, Vector2 RectSize);
}