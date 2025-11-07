#include "Player.h"

namespace player
{
    void player::Movement(Player& player)
    {
        player.position.x = 200;

        if (player.acceleration < 3)
        {
            player.acceleration += 4.2f * GetFrameTime();
        }
        player.position.y += GetFrameTime() * player.acceleration * Game::speed;

        if (player.position.y <= 0 && player.acceleration < 0)
        {
            player.acceleration = 0 ;
        }

        if (IsKeyPressed('w') || IsKeyPressed('W') || IsKeyPressed(KEY_SPACE))
        {
            player.acceleration = -2.0;
        }
    }
}