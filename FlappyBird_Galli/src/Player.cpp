#include "Player.h"

namespace player
{
    void player::Movement(Player& player)
    {
        player.position.x = 200;

        if (player.acceleration < 2)
        {
            player.acceleration += 0.005f;
        }
        player.position.y += GetFrameTime() * player.acceleration * Game::speed;

        if (player.position.y < 0)
        {
            player.position.y += 1;
        }

        if (IsKeyPressed('w') || IsKeyPressed('W'))
        {
            player.acceleration = -5;
        }
    }
}