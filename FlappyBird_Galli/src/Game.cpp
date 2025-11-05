#include "Game.h"
#include "Player.h"
#include "Obstacle.h"
#include "Collisions.h"


int Game()
{

    Vector2 playerPos = { 0 };
    float playerSize = 40;

    Vector2 obstaclePos[2] = { {0} };

    float acceleration = 0;
    float speed = 200.0f;


    while (!WindowShouldClose())
    {
        PlayerMovement(playerPos, acceleration, speed);

        ObstacleMovement(obstaclePos, speed);

        if (rectToRect(playerPos,{playerSize,playerSize},obstaclePos[0], {40,screenHeight}) || 
            rectToRect(playerPos, { playerSize,playerSize }, obstaclePos[1], { 40,screenHeight }) ||
            playerPos.y + playerSize >= screenHeight)
        {
            playerPos.y = 0;
            obstaclePos[0].x = 0 - 40;
            obstaclePos[1].x = 0 - 40;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangleV(playerPos, { 40,40 }, BLACK);

        DrawRectangleV(obstaclePos[0], {40,screenHeight}, BLACK);
        DrawRectangleV(obstaclePos[1], {40,screenHeight}, BLACK);

        DrawText("0.2", 5, 5, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}