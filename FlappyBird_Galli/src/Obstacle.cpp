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
            obstacle[0].position.y = (rand() % (program::screenHeight - 100)) + 100;
            obstacle[1].position.y = (obstacle[0].position.y - program::screenHeight) - 150;
        }
    }
}