#include "Obstacle.h"

namespace obstacle
{
    void obstacle::Movement(Obstacle obstacle[2])
    {

        obstacle[0].position.x -= 1 * GetFrameTime() * Game::speed;
        obstacle[1].position.x -= 1 * GetFrameTime() * Game::speed;

        if (obstacle[0].position.x < 0 - 40)
        {
            obstacle[0].position.x = program::screenWidth;
            obstacle[1].position.x = program::screenWidth;
            obstacle[0].position.y = static_cast<float>((rand() % (static_cast<int>(program::screenHeight - 100.0))) + 100.0);
            obstacle[1].position.y = static_cast<float>((obstacle[0].position.y - program::screenHeight) - 200.0);
        }
    }
}