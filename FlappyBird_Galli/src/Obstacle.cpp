#include "Obstacle.h"

void ObstacleMovement(Vector2 obstaclePos[], float speed)
{
    obstaclePos[0].x -= 1 * GetFrameTime() * speed;
    obstaclePos[1].x -= 1 * GetFrameTime() * speed;

    if (obstaclePos[0].x < 0 - 40)
    {
        obstaclePos[0].x = screenWidth;
        obstaclePos[1].x = screenWidth;
        obstaclePos[0].y = (rand() % (screenHeight - 100)) + 100;
        obstaclePos[1].y = (obstaclePos[0].y - screenHeight) - 150;
    }
}