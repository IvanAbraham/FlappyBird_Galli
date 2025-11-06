#include "Obstacle.h"

namespace obstacle
{
    void obstacle::Movement(Obstacle obstacle[2])
    {
        obstacle[0].position.x -= 1 * GetFrameTime() * Game::speed;
        obstacle[1].position.x -= 1 * GetFrameTime() * Game::speed;

        if (obstacle[0].position.x < 0 - 40)
        {
            obstacle[0].position.x = screenWidth;
            obstacle[1].position.x = screenWidth;
            obstacle[0].position.y = (rand() % (screenHeight - 100)) + 100;
            obstacle[1].position.y = (obstacle[0].position.y - screenHeight) - 150;
        }
    }
}