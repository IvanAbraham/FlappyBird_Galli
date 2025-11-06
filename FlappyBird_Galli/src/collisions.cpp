#include "Collisions.h"
namespace col
{
	bool rectToRect(Vector2 Rect1, Vector2 Rect1Size, Vector2 Rect2, Vector2 Rect2Size)
	{
		if (Rect1.x > Rect2.x &&
			Rect1.x < Rect2.x + Rect2Size.x &&
			Rect1.y > Rect2.y &&
			Rect1.y < Rect2.y + Rect2Size.y)
		{
			return true;
		}
		if (Rect1.x + Rect1Size.x > Rect2.x &&
			Rect1.x + Rect1Size.x < Rect2.x + Rect2Size.x &&
			Rect1.y > Rect2.y &&
			Rect1.y < Rect2.y + Rect2Size.y)
		{
			return true;
		}
		if (Rect1.x > Rect2.x &&
			Rect1.x < Rect2.x + Rect2Size.x &&
			Rect1.y + Rect1Size.y > Rect2.y &&
			Rect1.y + Rect1Size.y < Rect2.y + Rect2Size.y)
		{
			return true;
		}
		if (Rect1.x + Rect1Size.x > Rect2.x &&
			Rect1.x + Rect1Size.x < Rect2.x + Rect2Size.x &&
			Rect1.y + Rect1Size.y > Rect2.y &&
			Rect1.y + Rect1Size.y < Rect2.y + Rect2Size.y)
		{
			return true;
		}
		return false;
	}

	bool pointToRect(Vector2 point, Vector2 Rect, Vector2 RectSize)
	{
		if (point.x > Rect.x && 
			point.x < Rect.x + RectSize.x &&
			point.y > Rect.y && 
			point.y < Rect.y + RectSize.y)
		{
			return true;
		}
		return false;
	}
}