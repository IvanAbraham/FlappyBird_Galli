#include "Game.h"

void Game::Update()
{
    static player::Player player;
    static obstacle::Obstacle obstacle[2];

    player::Movement(player);

    obstacle::Movement(obstacle);

    if (col::rectToRect(player.position, player.size, obstacle[0].position, { 40,screenHeight }) ||
        col::rectToRect(player.position, player.size, obstacle[1].position, { 40,screenHeight }) ||
        player.position.y + player.size.y >= screenHeight)
    {
        player.position.y = 0;
        obstacle[0].position.x = 0 - 40;
        obstacle[1].position.x = 0 - 40;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangleV(player.position, player.size, BLACK);

    DrawRectangleV(obstacle[0].position, { 40,screenHeight }, BLACK);
    DrawRectangleV(obstacle[1].position, { 40,screenHeight }, BLACK);

    DrawText("0.2", 5, 5, 10, BLACK);

    EndDrawing();
}