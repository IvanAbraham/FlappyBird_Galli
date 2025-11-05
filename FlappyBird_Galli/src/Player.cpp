#include "Player.h"

void PlayerMovement(Vector2& playerPos,float& acceleration, float speed)
{

    playerPos.x = 200;
    
    if (acceleration < 2)
    {
        acceleration += 0.005f;
    }
    playerPos.y += GetFrameTime() * acceleration * speed;

    if (playerPos.y < 0)
    {
        playerPos.y += 1;
    }

    if (IsKeyPressed('w') || IsKeyPressed('W'))
    {   
        acceleration = -5;
    }
}